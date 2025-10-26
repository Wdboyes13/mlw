#include "vm_class.hpp"

llvm::GenericValue MLWVM::runFunction(const std::string& functionName,
                                    const std::vector<llvm::GenericValue>& args) {
    if (!jit) {
        llvm::errs() << "JIT not initialized. Call finalize() first.\n";
        return llvm::GenericValue();
    }

    // Lookup the function
    auto sym = jit->lookup(functionName);
    if (!sym) {
        llvm::errs() << "Function '" << functionName << "' not found: "
                    << llvm::toString(sym.takeError()) << "\n";
        return llvm::GenericValue();
    }

    llvm::errs() << "Executing function: " << functionName << "\n";

    // Cast to function pointer and call
    using MainFunc = int(*)(void);
    auto funcPtr = sym.get().toPtr<MainFunc>();
    int result = funcPtr();

    // Convert to GenericValue
    llvm::GenericValue gv;
    gv.IntVal = llvm::APInt(32, result);
    return gv;
}