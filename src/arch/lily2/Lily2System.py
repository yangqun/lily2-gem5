# -*- mode:python -*-

# Copyright (c) 2007 MIPS Technologies, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Authors: Jaidev Patwardhan

# Modifier: Li Xiaotian
# Description: MIPS===>LILY2
#              Mips===>Lily2
#              mips===>lily2

from m5.defines import buildEnv
from m5.params import *
from m5.proxy import *

from System import System

class Lily2System(System):
    type = 'Lily2System'
    console = Param.String("file that contains the console code")
    bare_iron = Param.Bool(False, "Using Bare Iron Mode?")
    hex_file_name = Param.String("test.hex","hex file that contains [address,data] pairs")
    system_type = Param.UInt64("Type of system we are emulating")
    system_rev = Param.UInt64("Revision of system we are emulating")
    load_addr_mask = 0xffffffffff

class LinuxLily2System(Lily2System):
    type = 'LinuxLily2System'
    system_type = 34
    system_rev = 1 << 10

    boot_cpu_frequency = Param.Frequency(Self.cpu[0].clock.frequency,
                                         "boot processor frequency")

class BareIronLily2System(Lily2System):
    type = 'BareIronLily2System'
    bare_iron = True
    system_type = 34
    system_rev = 1 << 10
    hex_file_name = Param.String('test.hex',"hex file that contains [address,data] pairs")

