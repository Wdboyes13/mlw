use clap::Parser;
use std::fmt::Debug;
use std::fs::{self, File};
use std::io::{BufRead, BufReader};
use std::path::PathBuf;
use thiserror::Error;

fn clap_path_handler(s: &str) -> Result<PathBuf, String> {
    let path = PathBuf::from(s);
    if path.exists() {
        Ok(path)
    } else {
        Err(format!("path does not exist {}", s))
    }
}

#[derive(Parser, Clone)]
struct Cli {
    #[arg(help = "The file to preprocess")]
    file: String,

    #[arg(short = 'I', value_name = "PATH", help = "Include paths to search", value_parser = clap_path_handler)]
    include_paths: Vec<PathBuf>,

    #[arg(
        help = "enable debugging",
        default_value_t = false,
        short = 'd',
        long = "debug"
    )]
    debug: bool,
}

#[derive(Error, Debug)]
enum PpError {
    #[error("no identifer")]
    NoIdent,
    #[error("bad identifier")]
    BadIdent,
    #[error("unknown directive")]
    UnknownDirective,
    #[error("include not found")]
    NotFound,
    #[error("internal error: {0}")]
    Internal(#[from] std::io::Error),
}

struct DebugInfo {
    debug: bool,
    line: usize,
}

macro_rules! debug {
    ($dbginfo:ident, $($arg:tt)*) => {
        if $dbginfo.debug {
            eprintln!("[debug @ line:{}] {}", $dbginfo.line, format_args!($($arg)*))
        }
    };
}

fn pp_include_get_name(pp_string: &str) -> Result<&str, PpError> {
    if pp_string.starts_with('"') && pp_string.ends_with('"') {
        Ok(&pp_string[1..pp_string.len() - 1])
    } else if pp_string.starts_with('<') && pp_string.ends_with('>') {
        Ok(&pp_string[1..pp_string.len() - 1])
    } else {
        Err(PpError::BadIdent)
    }
}

fn pp_include_get_path(name: &str, include_paths: &[PathBuf]) -> Result<PathBuf, PpError> {
    if !fs::exists(name)? {
        for path in include_paths {
            let possible_path = path.join(name);
            if possible_path.exists() {
                return Ok(fs::canonicalize(possible_path)?);
            }
        }
        Err(PpError::NotFound)
    } else {
        Ok(fs::canonicalize(name)?)
    }
}

fn pp_handle_include(
    pp_string: &str,
    include_paths: &[PathBuf],
    debug: DebugInfo,
) -> Result<String, PpError> {
    let name = pp_include_get_name(pp_string)?;
    debug!(debug, "include ident: {}", name);

    let path = pp_include_get_path(name, include_paths)?;
    debug!(debug, "include path resolved: {}", path.display());

    Ok(std::fs::read_to_string(path)?)
}

fn process_line(input: String, cli: &Cli, debug: DebugInfo) -> Result<String, PpError> {
    let Some(pp_at) = input.find('@') else {
        return Ok(input.to_string());
    };

    let rest = &input[pp_at + 1..].trim();
    let (directive, args) = rest
        .split_once(|c: char| c.is_whitespace())
        .ok_or(PpError::NoIdent)?;
    let args = args.trim();

    match directive {
        "include" => pp_handle_include(args, &cli.include_paths, debug),
        _ => Err(PpError::UnknownDirective),
    }
}

fn main() -> Result<(), PpError> {
    let cli = Cli::parse();
    BufReader::new(File::open(&cli.file)?)
        .lines()
        .enumerate()
        .map(|(line_num, line)| {
            process_line(
                line?,
                &cli,
                DebugInfo {
                    debug: cli.debug,
                    line: line_num,
                },
            )
        })
        .collect::<Result<Vec<String>, _>>()?
        .iter()
        .for_each(|line| println!("{line}"));
    Ok(())
}
