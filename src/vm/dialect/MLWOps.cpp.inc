/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MLWDialect.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlw::ImplibsOp
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlw {

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MLWDialect1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !((::llvm::isa<::mlir::ArrayAttr>(attr))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: array attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MLWDialect1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MLWDialect1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
} // namespace mlw
namespace mlw {

//===----------------------------------------------------------------------===//
// ::mlw::ImplibsOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
ImplibsOpGenericAdaptorBase::ImplibsOpGenericAdaptorBase(ImplibsOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

::mlir::ArrayAttr ImplibsOpGenericAdaptorBase::getLibraries() {
  auto attr = getLibrariesAttr();
  return attr;
}

} // namespace detail
ImplibsOpAdaptor::ImplibsOpAdaptor(ImplibsOp op) : ImplibsOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ImplibsOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_libraries = getProperties().libraries; (void)tblgen_libraries;
  if (!tblgen_libraries) return emitError(loc, "'mlw.implibs' op ""requires attribute 'libraries'");

  if (tblgen_libraries && !((::llvm::isa<::mlir::ArrayAttr>(tblgen_libraries))))
    return emitError(loc, "'mlw.implibs' op ""attribute 'libraries' failed to satisfy constraint: array attribute");
  return ::mlir::success();
}

::llvm::LogicalResult ImplibsOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.libraries;
       auto attr = dict.get("libraries");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `libraries` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute ImplibsOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.libraries;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("libraries",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code ImplibsOp::computePropertiesHash(const Properties &prop) {
  return llvm::hash_combine(
    llvm::hash_value(prop.libraries.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> ImplibsOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "libraries")
      return prop.libraries;
  return std::nullopt;
}

void ImplibsOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "libraries") {
       prop.libraries = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.libraries)>>(value);
       return;
    }
}

void ImplibsOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.libraries) attrs.append("libraries", prop.libraries);
}

::llvm::LogicalResult ImplibsOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getLibrariesAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MLWDialect1(attr, "libraries", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult ImplibsOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.libraries)))
    return ::mlir::failure();
  return ::mlir::success();
}

void ImplibsOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.libraries);
}

::mlir::ArrayAttr ImplibsOp::getLibraries() {
  auto attr = getLibrariesAttr();
  return attr;
}

void ImplibsOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ArrayAttr libraries) {
  odsState.getOrAddProperties<Properties>().libraries = libraries;
}

void ImplibsOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ArrayAttr libraries) {
  odsState.getOrAddProperties<Properties>().libraries = libraries;
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ImplibsOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    ::mlir::OpaqueProperties properties =
      &odsState.getOrAddProperties<ImplibsOp::Properties>();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

::llvm::LogicalResult ImplibsOp::verifyInvariantsImpl() {
  auto tblgen_libraries = getProperties().libraries; (void)tblgen_libraries;
  if (!tblgen_libraries) return emitOpError("requires attribute 'libraries'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MLWDialect1(*this, tblgen_libraries, "libraries")))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::LogicalResult ImplibsOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult ImplibsOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::ArrayAttr librariesAttr;
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseKeyword("libraries"))
    return ::mlir::failure();
  if (parser.parseEqual())
    return ::mlir::failure();

  if (parser.parseCustomAttributeWithFallback(librariesAttr, parser.getBuilder().getType<::mlir::NoneType>())) {
    return ::mlir::failure();
  }
  if (librariesAttr) result.getOrAddProperties<ImplibsOp::Properties>().libraries = librariesAttr;
  return ::mlir::success();
}

void ImplibsOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  elidedAttrs.push_back("libraries");
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << "libraries";
  _odsPrinter << ' ' << "=";
  _odsPrinter << ' ';
  _odsPrinter.printAttributeWithoutType(getLibrariesAttr());
}

} // namespace mlw
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlw::ImplibsOp)


#endif  // GET_OP_CLASSES

