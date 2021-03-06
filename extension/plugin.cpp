#include <extension/Extension.h>
#if MTOA12
#include <extension/ExtensionsManager.h>
#elif MTOA14
#include <extension/Extension.h>
#endif


#include "openvdb_translator.h"
#include "sampler_translator.h"
#include "shader_translator.h"
#include "simple_shader_translator.h"

extern "C"
{
DLLEXPORT void initializeExtension(CExtension& extension)
{
    extension.Requires("openvdb_render");

    extension.RegisterTranslator("vdb_visualizer",
                                 "",
                                 OpenvdbTranslator::creator);

    extension.RegisterTranslator("vdb_sampler",
                                 "",
                                 SamplerTranslator::creator);

    extension.RegisterTranslator("vdb_shader",
                                 "",
                                 VDBShaderTranslator::creator);

    extension.RegisterTranslator("vdb_simple_shader",
                                 "",
                                 VDBSimpleShaderTranslator::creator);
}

DLLEXPORT void deinitializeExtension(CExtension&)
{
}
}
