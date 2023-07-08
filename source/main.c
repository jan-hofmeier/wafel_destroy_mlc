#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <wafel/dynamic.h>
#include <wafel/ios_dynamic.h>
#include <wafel/utils.h>
#include <wafel/patch.h>

// This fn runs before everything else in kernel mode.
// It should be used to do extremely early patches
// (ie to BSP and kernel, which launches before MCP)
// It jumps to the real IOS kernel entry on exit.
__attribute__((target("arm")))
void kern_main()
{
    // Make sure relocs worked fine and mappings are good
    debug_printf("we in here destroy mlc plugin kern %p\n", kern_main);

    debug_printf("init_linking symbol at: %08x\n", wafel_find_symbol("init_linking"));

    // Limit MLC size to...
    ASM_PATCH_K(0x107bdb10,
          "nop\n"
          "nop\n"
          "nop\n"
          "ldr r4, [pc, #0xb8]\n"
        );
    // MLC size in LBAs (5GB)
    U32_PATCH_K(0x107bdbdc, 0xA00000);

    // Format MLC if needed
    ASM_PATCH_K(0x05027D24, ".thumb\nnop\nnop\n");
}

// This fn runs before MCP's main thread, and can be used
// to perform late patches and spawn threads under MCP.
// It must return.
void mcp_main()
{

}
