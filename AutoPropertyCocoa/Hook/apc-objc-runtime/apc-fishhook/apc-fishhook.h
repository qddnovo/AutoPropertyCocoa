/**
 AutoPropertyCocoa
 : In order to get rid of cocoapods, fishhook only depends on the iOS platform. This project has a built-in fishhook.Supported the macOS platform.
 */

// Copyright (c) 2013, Facebook, Inc.
// All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name Facebook nor the names of its contributors may be used to
//     endorse or promote products derived from this software without specific
//     prior written permission.
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef apc_fishhook_h
#define apc_fishhook_h

#include <stddef.h>
#include <stdint.h>

#if !defined(APC_FISHHOOK_EXPORT)
#define APC_FISHHOOK_VISIBILITY __attribute__((visibility("hidden")))
#else
#define APC_FISHHOOK_VISIBILITY __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/*
 * A structure representing a particular intended apc_rebinding from a symbol
 * name to its replacement
 */
struct apc_rebinding {
  const char *name;
  void *replacement;
  void **replaced;
};

/*
 * For each apc_rebinding in apc_rebindings, rebinds references to external, indirect
 * symbols with the specified name to instead point at replacement for each
 * image in the calling process as well as for all future images that are loaded
 * by the process. If rebind_functions is called more than once, the symbols to
 * rebind are added to the existing list of apc_rebindings, and if a given symbol
 * is rebound more than once, the later apc_rebinding will take precedence.
 */
APC_FISHHOOK_VISIBILITY
int apc_rebind_symbols(struct apc_rebinding apc_rebindings[], size_t apc_rebindings_nel);

/*
 * Rebinds as above, but only in the specified image. The header should point
 * to the mach-o header, the slide should be the slide offset. Others as above.
 */
APC_FISHHOOK_VISIBILITY
int apc_rebind_symbols_image(void *header,
                         intptr_t slide,
                         struct apc_rebinding apc_rebindings[],
                         size_t apc_rebindings_nel);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //apc_fishhook_h

