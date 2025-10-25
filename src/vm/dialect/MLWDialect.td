#ifndef MLW_OPS
#define MLW_OPS

include "mlir/IR/OpBase.td"
include "mlir/IR/DialectBase.td"

def MLW_Dialect : Dialect {
    let name = "mlw";
    let cppNamespace = "::mlw";
    let description = [{
        The MLW dialect contains operations for the MLW VM and Compiler
    }];
}

class MLW_Op<string mnemonic, list<Trait> traits = []> :
    Op<MLW_Dialect, mnemonic, traits>;

def MLW_ImplibsOp : MLW_Op<"implibs"> {
    let summary = "Import Libraries";
    let description = [{
        Contains the list of shared libraries that this module depends on.
        This operation should appear at most once per module.
      }];

    let arguments = (ins ArrayAttr:$libraries);

    let assemblyFormat = "attr-dict `libraries` `=` $libraries";
    let hasVerifier = 1;
}

#endif // MLW_OPS