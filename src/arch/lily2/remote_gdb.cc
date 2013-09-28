/*
 * Copyright (c) 2010 ARM Limited
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2002-2005 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Nathan Binkert
 *          William Wang
 *          Deyuan Guo
 */

/**
 * Modifier: Li Xiaotian
 * Description: MIPS===>LILY2
 *              Mips===>Lily2
 *              mips===>lily2
 */

/*
 * Copyright (c) 1990, 1993 The Regents of the University of California
 * All rights reserved
 *
 * This software was developed by the Computer Systems Engineering group
 * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and
 * contributed to Berkeley.
 *
 * All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Lawrence Berkeley Laboratories.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      @(#)kgdb_stub.c 8.4 (Berkeley) 1/12/94
 */

/*-
 * Copyright (c) 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Jason R. Thorpe.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the NetBSD
 *      Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * $NetBSD: kgdb_stub.c,v 1.8 2001/07/07 22:58:00 wdk Exp $
 *
 * Taken from NetBSD
 *
 * "Stub" to allow remote cpu to debug over a serial line using gdb.
 */

#include <sys/signal.h>
#include <unistd.h>

#include <string>
#include <cstdio>

#include <iostream>
#include "arch/lily2/decoder.hh"
#include "arch/lily2/remote_gdb.hh"
#include "arch/lily2/vtophys.hh"
#include "cpu/thread_state.hh"
#include "debug/GDBAcc.hh"
#include "debug/GDBMisc.hh"
#include "mem/page_table.hh"
#include "sim/full_system.hh"
#include "arch/lily2/lily2_traits/register.hh"

using namespace std;
using namespace Lily2ISA;

RemoteGDB::RemoteGDB(System *_system, ThreadContext *tc)
    : BaseRemoteGDB(_system, tc, GdbNumRegs)
{
}

/*
 * Determine if the mapping at va..(va+len) is valid.
 */
bool
RemoteGDB::acc(Addr va, size_t len)
{
    TlbEntry entry;
    //Check to make sure the first byte is mapped into the processes address
    //space.
    if (FullSystem)
        panic("acc not implemented for MIPS FS!");
    else
        return context->getProcessPtr()->pTable->lookup(va, entry);
}

// This function does all command processing for interfacing to a
// remote gdb.  Note that the error codes are ignored by gdb at
// present, but might eventually become meaningful. (XXX) It might
// makes sense to use POSIX errno values, because that is what the
// gdb/remote.c functions want to return.
bool
RemoteGDB::trap(int type)
{
    uint64_t val;
    size_t datalen, len;
    char data[GDBPacketBufLen + 1];
    char *buffer;
    size_t bufferSize;
    const char *p;
    char command, subcmd;
    string var;
    bool ret;

    int idx;
    uint64_t * regval;

    if (!attached)
        return false;

    bufferSize = gdbregs.bytes() * 2 + 256;
    buffer = (char*)malloc(bufferSize);

    DPRINTF(GDBMisc, "trap: PC=%s\n", context->pcState());

    clearSingleStep();
	clearsi();

    /*
     * The first entry to this function is normally through
     * a breakpoint trap in kgdb_connect(), in which case we
     * must advance past the breakpoint because gdb will not.
     *
     * On the first entry here, we expect that gdb is not yet
     * listening to us, so just enter the interaction loop.
     * After the debugger is "active" (connected) it will be
     * waiting for a "signaled" message from us.
     */
    if (!active)
        active = true;
    else
        // Tell remote host that an exception has occurred.
        snprintf((char *)buffer, bufferSize, "S%02x", type);
        send(buffer);

    // Stick frame regs into our reg cache.
    getregs();

    for (;;) {
        datalen = recv(data, sizeof(data));
        data[sizeof(data) - 1] = 0; // Sentinel
        command = data[0];
        subcmd = 0;
        p = data + 1;
		//std::cout << "packet is: " << data[1] <<data[2]<<std::endl;
        switch (command) {
          case GDBSignal:
            // if this command came from a running gdb, answer it --
            // the other guy has no way of knowing if we're in or out
            // of this loop when he issues a "remote-signal".
            snprintf((char *)buffer, bufferSize,
                    "S%02x", type);
            send(buffer);
            continue;

          case GDBRegR:  //'g'
            if (2 * gdbregs.bytes() > bufferSize)
                panic("buffer too small");

            mem2hex(buffer, gdbregs.regs, gdbregs.bytes());
            send(buffer);
            continue;

          case GDBRegW:   //'G'
            p = hex2mem(gdbregs.regs, p, gdbregs.bytes());
            if (p == NULL || *p != '\0')
                send("E01");
            else {
                setregs();
                send("OK");
            }
            continue;

#if 0
          case GDBSetReg:
            val = hex2i(&p);
            if (*p++ != '=') {
                send("E01");
                continue;
            }
            if (val < 0 && val >= KGDB_NUMREGS) {
                send("E01");
                continue;
            }

            gdbregs.regs[val] = hex2i(&p);
            setregs();
            send("OK");

            continue;
#endif

          case GDBMemR:  //'m' read memory
            val = hex2i(&p);
            if (*p++ != ',') {
                send("E02");
                continue;
            }
            len = hex2i(&p);
            if (*p != '\0') {
                send("E03");
                continue;
            }
            if (len > bufferSize) {
                send("E04");
                continue;
            }
            if (!acc(val, len)) {
                send("E05");
                continue;
            }

            if (read(val, (size_t)len, (char *)buffer)) {
               // variable length array would be nice, but C++ doesn't
               // officially support those...
               char *temp = new char[2*len+1];
			   mem2hex(temp, buffer, len);

               send(temp);
               delete [] temp;
			   //delete [] dst1;
            } else {
               send("E05");
            }
            continue;

          case GDBMemW:
            val = hex2i(&p);
            if (*p++ != ',') {
                send("E06");
                continue;
            }
            len = hex2i(&p);
            if (*p++ != ':') {
                send("E07");
                continue;
            }
            if (len > datalen - (p - data)) {
                send("E08");
                continue;
            }
            p = hex2mem(buffer, p, bufferSize);
            if (p == NULL) {
                send("E09");
                continue;
            }
            if (!acc(val, len)) {
                send("E0A");
                continue;
            }
            if (write(val, (size_t)len, (char *)buffer))
              send("OK");
            else
              send("E0B");
            continue;

          case GDBSetThread:
            subcmd = *p++;
            val = hex2i(&p);
            if (val == 0)
                send("OK");
            else
                send("E01");
            continue;

          case GDBDetach:  //D
          case GDBKill:    //k
            active = false;
            clearSingleStep();
            detach();
            goto out;

          case GDBAsyncCont://C04#a7
            subcmd = hex2i(&p);
            //printf("GDBAsyncCont subcmd is:%d\n",subcmd);
            if (*p++ == ';') {
                val = hex2i(&p);
				//printf("GDBAsyncCont address is: %x\n",val);
                context->pcState(val);
            }
            clearSingleStep();
            goto out;

          case GDBCont:
            if (p - data < (ptrdiff_t)datalen) {
                val = hex2i(&p);
                context->pcState(val);
            }
            clearSingleStep();
            goto out;

          case GDBAsyncStep:   //S04#b7  si
            subcmd = hex2i(&p);
			printf("GDBAsyncStep subcmd is:%d\n",subcmd);
            if (*p++ == ';') {
                val = hex2i(&p);
				//printf("GDBAsyncStep address is: %x\n",val);
                context->pcState(val);
            }
            setSingleStep();
            goto out;

          case GDBStep:
            if (p - data < (ptrdiff_t)datalen) {
                val = hex2i(&p);
                context->pcState(val);
            }
            setSingleStep();
            goto out;

          case GDBClrHwBkpt:
            subcmd = *p++;
            if (*p++ != ',') send("E0D");
            val = hex2i(&p);
            if (*p++ != ',') send("E0D");
            len = hex2i(&p);

            DPRINTF(GDBMisc, "clear %s, addr=%#x, len=%d\n",
                    break_type(subcmd), val, len);

            ret = false;

            switch (subcmd) {
              case '0': // software breakpoint
                ret = removeSoftBreak(val, len);
                break;

              case '1': // hardware breakpoint
                ret = removeHardBreak(val, len);
                break;

              case '2': // write watchpoint
              case '3': // read watchpoint
              case '4': // access watchpoint
              default: // unknown
                send("");
                break;
            }

            send(ret ? "OK" : "E0C");
            continue;

          case GDBSetHwBkpt:
            subcmd = *p++;
            if (*p++ != ',') send("E0D");
            val = hex2i(&p);
            if (*p++ != ',') send("E0D");
            len = hex2i(&p);
            //printf("Address is: %x, length is:%d\n",val,len);
            DPRINTF(GDBMisc, "set %s, addr=%#x, len=%d\n",
                    break_type(subcmd), val, len);

            ret = false;

            switch (subcmd) {
              case '0': // software breakpoint
                ret = insertSoftBreak(val, len);
                break;

              case '1': // hardware breakpoint
                ret = insertHardBreak(val, len);
                break;

              case '2': // write watchpoint
              case '3': // read watchpoint
              case '4': // access watchpoint
              default: // unknown
                send("");
                break;
            }

            send(ret ? "OK" : "E0C");
            continue;

          case GDBQueryVar:
            var = string(p, datalen - 1);
            if (var == "C")
                send("QC0");
            else
                send("");
            continue;

          case GDBSetBaud:
          case GDBSetBreak:
          case GDBDebug:
          case GDBCycleStep:
          case GDBSigCycleStep:
          case GDBReadReg:
		    printf("GDBREADREG\n");
			idx=digit2i(data[1])*16 + digit2i(data[2]);
			printf("GDBREADREG idx is: %d\n",idx);
            regval = &gdbregs.regs[idx];
            //send(regval);
			mem2hex(buffer, regval, 4);
            send(buffer);
			continue;
          case GDBSetVar:
          case GDBReset:
          case GDBThreadAlive:
          case GDBTargetExit:
          case GDBBinaryDload:
            // Unsupported command
            DPRINTF(GDBMisc, "Unsupported command: %s\n",
                    gdb_command(command));
            DDUMP(GDBMisc, (uint8_t *)data, datalen);
            send("");
            continue;

          default:
            // Unknown command.
            DPRINTF(GDBMisc, "Unknown command: %c(%#x)\n",
                    command, command);
            send("");
            continue;


        }
    }

  out:
    free(buffer);
    return true;
}


/*
 * Translate the kernel debugger register format into the GDB register
 * format.
 */
void
RemoteGDB::getregs()
{
	// X0~X23
	for(int i = 0; i < LILY2_NS::Num_X_Regs; i++) { //LILY2_NS::Num_X_Regs
		gdbregs.regs[i]=context->getCpuPtr()->read_x_reg(i);
		//gdbregs.regs[LILY2_NS::Num_X_Regs]=pack(context->getCpuPtr()->read_x_reg(i*2),context->getCpuPtr()->read_x_reg(i*2+1));
	}
    /*for(int i = 0; i != LILY2_NS::Num_G_Regs; i++) {
		gdbregs.regs[24+4*i]  =context->getCpuPtr()->read_g_reg(i)._h3;
		gdbregs.regs[24+1+4*i]=context->getCpuPtr()->read_g_reg(i)._h2;
		gdbregs.regs[24+2+4*i]=context->getCpuPtr()->read_g_reg(i)._h1;
		gdbregs.regs[24+3+4*i]=context->getCpuPtr()->read_g_reg(i)._h0;
    }
	for(int i =0; i < LILY2_NS::Num_Y_Regs; i++){
		gdbregs.regs[56+4*i]  =context->getCpuPtr()->read_y_reg(i)._h3;
		gdbregs.regs[56+1+4*i]=context->getCpuPtr()->read_y_reg(i)._h2;
		gdbregs.regs[56+2+4*i]=context->getCpuPtr()->read_y_reg(i)._h1;
		gdbregs.regs[56+3+4*i]=context->getCpuPtr()->read_y_reg(i)._h0;
	}*/
	gdbregs.regs[57]=context->getCpuPtr()->read_pc();//pc
    //gdbregs.regs[33]=10010;//RA
	// Y
	//for(int i = 0; i != LILY2_NS::Num_Y_Regs; i++) {
	//	tc->getCpuPtr()->get_y_regfile()->read(i);
	//}
	// G0~G8
	//for(int i = 0; i != LILY2_NS::Num_G_Regs; i++) {
	//	gdbregs.regs[12+i]=context->getCpuPtr()->read_g_reg(i);
//gdbregs.regs[12+i]=pack(context->getCpuPtr()->read_g_reg(i*2),context->getCpuPtr()->read_g_reg(i*2+1));
//	}
	// PC
	//tc->getCpuPtr()->get_pcs()->get_fetch_addr();
	/*
    DPRINTF(GDBAcc, "getregs in remotegdb \n");
    memset(gdbregs.regs, 0, gdbregs.bytes());

    // MIPS registers are 32 bits wide, gdb registers are 64 bits wide
    // two MIPS registers are packed into one gdb register (little endian)

    // INTREG: R0~R31
    for (int i = 0; i < GdbIntArchRegs; i++) {
        gdbregs.regs[i] = pack(
                context->readIntReg(i * 2),
                context->readIntReg(i * 2 + 1));
    }
    // SR, LO, HI, BADVADDR, CAUSE, PC
    gdbregs.regs[GdbIntArchRegs + 0] = pack(
                context->readMiscRegNoEffect(MISCREG_STATUS),
                context->readIntReg(INTREG_LO));
    gdbregs.regs[GdbIntArchRegs + 1] = pack(
                context->readIntReg(INTREG_HI),
                context->readMiscRegNoEffect(MISCREG_BADVADDR));
    gdbregs.regs[GdbIntArchRegs + 2] = pack(
                context->readMiscRegNoEffect(MISCREG_CAUSE),
                context->pcState().pc());
    // FLOATREG: F0~F31
    for (int i = 0; i < GdbFloatArchRegs; i++) {
        gdbregs.regs[GdbIntRegs + i] = pack(
                context->readFloatRegBits(i * 2),
                context->readFloatRegBits(i * 2 + 1));
    }
    // FCR, FIR
    gdbregs.regs[GdbIntRegs + GdbFloatArchRegs + 0] = pack(
                context->readFloatRegBits(FLOATREG_FCCR),
                context->readFloatRegBits(FLOATREG_FIR));
	*/
}

/*
 * Translate the GDB register format into the kernel debugger register
 * format.
 */
void
RemoteGDB::setregs()
{
    DPRINTF(GDBAcc, "setregs in remotegdb \n");

    // MIPS registers are 32 bits wide, gdb registers are 64 bits wide
    // two MIPS registers are packed into one gdb register (little endian)
    // X0~X23
	//for(int i = 0; i < LILY2_NS::Num_X_Regs; i++) { //LILY2_NS::Num_X_Regs

	//	context->getCpuPtr()->write_x_reg(i,gdbregs.regs[i]);
		//gdbregs.regs[LILY2_NS::Num_X_Regs]=pack(context->getCpuPtr()->read_x_reg(i*2),context->getCpuPtr()->read_x_reg(i*2+1));
//	}
    //for(int i = 0; i != LILY2_NS::Num_G_Regs; i++) {
	//	context->getCpuPtr()->write_g_reg(i,LILY2_NS::QWORD{0,0,0,8});// & 0xffffffff;//just get G regs' low 32bit data
    //}
	//context->getCpuPtr()->set_pc(gdbregs.regs[32]);//pc
    //gdbregs.regs[33]=10010;

	//for(int i=0;i < 24; i++){
	//	context->setIntReg(i, 2);		
			
//	}


    // INTREG: R0~R31
    /*for (int i = 0; i < GdbIntArchRegs; i++) {
        if (i) context->setIntReg(i * 2,
                unpackLo(gdbregs.regs[i]));
        context->setIntReg(i * 2 + 1,
                unpackHi(gdbregs.regs[i]));
    }
    // SR, LO, HI, BADVADDR, CAUSE, PC
    context->setMiscRegNoEffect(MISCREG_STATUS,
                unpackLo(gdbregs.regs[GdbIntArchRegs + 0]));
    context->setIntReg(INTREG_LO,
                unpackHi(gdbregs.regs[GdbIntArchRegs + 0]));
    context->setIntReg(INTREG_HI,
                unpackLo(gdbregs.regs[GdbIntArchRegs + 1]));
    context->setMiscRegNoEffect(MISCREG_BADVADDR,
                unpackHi(gdbregs.regs[GdbIntArchRegs + 1]));
    context->setMiscRegNoEffect(MISCREG_CAUSE,
                unpackLo(gdbregs.regs[GdbIntArchRegs + 2]));
    context->pcState(
                unpackHi(gdbregs.regs[GdbIntArchRegs + 2]));
    // FLOATREG: F0~F31
    for (int i = 0; i < GdbFloatArchRegs; i++) {
        context->setFloatRegBits(i * 2,
                unpackLo(gdbregs.regs[GdbIntRegs + i]));
        context->setFloatRegBits(i * 2 + 1,
                unpackHi(gdbregs.regs[GdbIntRegs + i]));
    }
    // FCR, FIR
    context->setFloatRegBits(FLOATREG_FCCR,
                unpackLo(gdbregs.regs[GdbIntRegs + GdbFloatArchRegs + 0]));
    context->setFloatRegBits(FLOATREG_FIR,
                unpackHi(gdbregs.regs[GdbIntRegs + GdbFloatArchRegs + 0]));
	*/
}

void
RemoteGDB::clearSingleStep()
{
    DPRINTF(GDBMisc, "clearSingleStep bt_addr=%#x nt_addr=%#x\n",
            takenBkpt, notTakenBkpt);

	//std::cout << "clearSingleStep"<<std::endl;
	//std::cout << "takenBkpt = 0x" << std::hex <<takenBkpt << std::endl;
	//std::cout << "nottakenBkpt = 0x" << std::hex << notTakenBkpt <<std::endl;
	if (takenBkpt != 0)
        clearTempBreakpoint(takenBkpt);

    if (notTakenBkpt != 0)
        clearTempBreakpoint(notTakenBkpt);
}

void
RemoteGDB::clearsi()
{
	for(int i = 0;i < tempbkptNum;i++)
		clearTempBreakpoint(tempbkpt[i]);

}

void
RemoteGDB::setSingleStep()
{
    PCState pc = context->pcState();
    PCState bpc;
    bool set_bt = false;
	//Addr tempbkpt[6];

    // User was stopped at pc, e.g. the instruction at pc was not
    // executed.
    MachInst inst = read<MachInst>(pc.pc());
    StaticInstPtr si = context->getDecoderPtr()->decode(inst, pc.pc());
    if (si->hasBranchTarget(pc, context, bpc)) {
        // Don't bother setting a breakpoint on the taken branch if it
        // is the same as the next npc
        if (bpc.npc() != pc.nnpc())
            set_bt = true;
    }

    DPRINTF(GDBMisc, "setSingleStep bt_addr=%#x nt_addr=%#x\n",
            takenBkpt, notTakenBkpt);

    notTakenBkpt = pc.nnpc();
	cout << "pc = 0x"<< hex << context->instAddr() <<endl; 
    //printf("pc = %#x\n",context->instAddr());
	for(int i = 0;i < tempbkptNum;i++)
	{
	  break_iter_t t = hardBreakMap.find(context->instAddr() + 2*i);
	  if(t == hardBreakMap.end())
	  {
	    tempbkpt[i] = context->instAddr() + 2*i;
	  }
	  else 
	  {
		printf("we have set breakpoint in this addr: 0x%x\n",(int)(context->instAddr() + 2*i));
        tempbkpt[i] = 0;
	  }
	    
	}

	if(context->getBranchTaken() == 1) {
		setTempBreakpoint(context->getBranchTarget() + 4);
	}
	else {
		for(int j = 0;j < tempbkptNum;j++)
		{
		  setTempBreakpoint(tempbkpt[j]);	
		}
		//setTempBreakpoint(context->instAddr() + 4);
	}
	//setTempBreakpoint(notTakenBkpt);
    //setTempBreakpoint(notTakenBkpt);
	/*
    if (set_bt) {
        takenBkpt = bpc.npc();
        setTempBreakpoint(takenBkpt);
    }*/
}

