/*++ 

Copyright (c) 2004, Intel Corporation                                                         
All rights reserved. This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

Module Name:

  ConsoleControl.h

Abstract:

  Abstraction of a Text mode or UGA screen



 rEFIt License
===============

Copyright (c) 2006 Christoph Pfisterer
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the
   distribution.

 * Neither the name of Christoph Pfisterer nor the names of the
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
--*/

#ifndef __CONSOLE_CONTROL_H__
#define __CONSOLE_CONTROL_H__

#define EFI_CONSOLE_CONTROL_PROTOCOL_GUID \
  { 0xf42f7782, 0x12e, 0x4c12, { 0x99, 0x56, 0x49, 0xf9, 0x43, 0x4, 0xf7, 0x21 } }

struct _EFI_CONSOLE_CONTROL_PROTOCOL;


typedef enum {
  EfiConsoleControlScreenText,
  EfiConsoleControlScreenGraphics,
  EfiConsoleControlScreenMaxValue
} EFI_CONSOLE_CONTROL_SCREEN_MODE;


typedef
EFI_STATUS
(EFIAPI *EFI_CONSOLE_CONTROL_PROTOCOL_GET_MODE) (
  IN  struct _EFI_CONSOLE_CONTROL_PROTOCOL *This,
  OUT EFI_CONSOLE_CONTROL_SCREEN_MODE   *Mode,
  OUT BOOLEAN                           *UgaExists,   OPTIONAL  
  OUT BOOLEAN                           *StdInLocked  OPTIONAL
  )
/*++

  Routine Description:
    Return the current video mode information. Also returns info about existence
    of UGA Draw devices in system, and if the Std In device is locked. All the
    arguments are optional and only returned if a non NULL pointer is passed in.

  Arguments:
    This - Protocol instance pointer.
    Mode        - Are we in text of grahics mode.
    UgaExists   - TRUE if UGA Spliter has found a UGA device
    StdInLocked - TRUE if StdIn device is keyboard locked

  Returns:
    EFI_SUCCESS     - Mode information returned.

--*/
;


typedef
EFI_STATUS
(EFIAPI *EFI_CONSOLE_CONTROL_PROTOCOL_SET_MODE) (
  IN  struct _EFI_CONSOLE_CONTROL_PROTOCOL *This,
  OUT EFI_CONSOLE_CONTROL_SCREEN_MODE   Mode
  )
/*++

  Routine Description:
    Set the current mode to either text or graphics. Graphics is
    for Quiet Boot.

  Arguments:
    This  - Protocol instance pointer.
    Mode  - Mode to set the 

  Returns:
    EFI_SUCCESS     - Mode information returned.

--*/
;


typedef
EFI_STATUS
(EFIAPI *EFI_CONSOLE_CONTROL_PROTOCOL_LOCK_STD_IN) (
  IN struct _EFI_CONSOLE_CONTROL_PROTOCOL *This,
  IN CHAR16                             *Password
  )
/*++

  Routine Description:
    Lock Std In devices until Password is typed.

  Arguments:
    This     - Protocol instance pointer.
    Password - Password needed to unlock screen. NULL means unlock keyboard

  Returns:
    EFI_SUCCESS      - Mode information returned.
    EFI_DEVICE_ERROR - Std In not locked

--*/
;



typedef struct _EFI_CONSOLE_CONTROL_PROTOCOL {
  EFI_CONSOLE_CONTROL_PROTOCOL_GET_MODE           GetMode;
  EFI_CONSOLE_CONTROL_PROTOCOL_SET_MODE           SetMode;
  EFI_CONSOLE_CONTROL_PROTOCOL_LOCK_STD_IN        LockStdIn;
} EFI_CONSOLE_CONTROL_PROTOCOL;

//extern EFI_GUID gEfiConsoleControlProtocolGuid;

#endif
