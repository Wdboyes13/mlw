# MLW (Mini-Language by Wdboyes13)
This is a small WIP programming language.  
Its syntax is based on Rust, and it's built on ANTLR4 and LLVM.  

## Features  
C Imports - Needed because we have litterally no standard library *yet* so just import everything from C   
> (They can't have file extensions though cause C++ hates me)   

Functions - Also needed, since without it the VM has litterally nothing to call  
Arithmetic - Because its a *real* programming lamguage (kinda)  
Variables - Because it's not HTML  
__and way more to come...__  

## Navigating the source code  
test/ - Some random tests I've done  
src/antlr - ANTLR4 Grammar & Generated code  
src/codegen/ir - IR Generation code   
src/codegen - Compiler driver   
vm/ - MLW Runtime (VM)  

## Example  
```  
!import printer
!extern println(i32) -> void

fn add(x: i32, y: i32) -> i32 {
    var res: i32 = x + y;
    return res;
}

fn main() -> i32 {
    var res: i32 = add(10, 10);
    println(res);
    return 0;
}  
```  


## License  
> Copyright (c) 2025 Wdboyes13  
> Licensed under the __MIT License__  
> SPDX-License-Identifier:MIT  