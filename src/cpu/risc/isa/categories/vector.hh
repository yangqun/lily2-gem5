/**
 * copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 06 May 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#ifndef __RISC_ISA_CATEGORIES_VECTOR_HH__
#define __RISC_ISA_CATEGORIES_VECTOR_HH__

#include "cpu/risc/isa/static_inst.hh"

namespace LILY2_NS
{
/* *********************************************************************
 * *************************** ADDV_A  ********************************
 * ********************************************************************/
class ADDV_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ADDV_A(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** SUBV_A ********************************
 * ********************************************************************/
class SUBV_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    SUBV_A(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** ABSV_A ********************************
 * ********************************************************************/
class ABSV_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    ABSV_A(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};
       
/* *********************************************************************
 * *************************** NEGV_A ********************************
 * ********************************************************************/
class NEGV_A : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    NEGV_A(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QADD_SP_D *******************************
 * ********************************************************************/
class QADD_SP_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QADD_SP_D(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QSUB_SP_D *******************************
 * ********************************************************************/
class QSUB_SP_D : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QSUB_SP_D(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QMPY_SP_M *******************************
 * ********************************************************************/
class QMPY_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QMPY_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QDIV_SP_M *******************************
 * ********************************************************************/
class QDIV_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QDIV_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};
 
/* *********************************************************************
 * ************************* QMPYADD_SP_M ******************************
 * ********************************************************************/
class QMPYADD_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QMPYADD_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * ************************* QNMPYADD_SP_M *****************************
 * ********************************************************************/
class QNMPYADD_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QNMPYADD_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * ************************ QMPYSUB_SP_M *******************************
 * ********************************************************************/
class QMPYSUB_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QMPYSUB_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QNMPYSUB_SP_M ***************************
 * ********************************************************************/
class QNMPYSUB_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QNMPYSUB_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};
 
/* *********************************************************************
 * *************************** QSQRT_SP_M ***************************
 * ********************************************************************/
class QSQRT_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QSQRT_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** SWAP_SP_M ***************************
 * ********************************************************************/
class SWAP_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    SWAP_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** PACKEVEN_SP_M ***************************
 * ********************************************************************/
class PACKEVEN_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    PACKEVEN_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** PACKODD_SP_M ***************************
 * ********************************************************************/
class PACKODD_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    PACKODD_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DPACK0_SP_M ***************************
 * ********************************************************************/
class DPACK0_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DPACK0_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DPACK1_SP_M ***************************
 * ********************************************************************/
class DPACK1_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DPACK1_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DPACK2_SP_M ***************************
 * ********************************************************************/
class DPACK2_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DPACK2_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DPACK3_SP_M ***************************
 * ********************************************************************/
class DPACK3_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DPACK3_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QPACKL_SP_M ***************************
 * ********************************************************************/
class QPACKL_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QPACKL_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** QPACKH_SP_M ***************************
 * ********************************************************************/
class QPACKH_SP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    QPACKH_SP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};

/* *********************************************************************
 * *************************** DINTSP_M ***************************
 * ********************************************************************/
class DINTSP_M : public StaticInst
{
public:
    /**
     * Constructor.
     * 
     * @param (mnemonic)  : Mnemonic of instruction.
     * @param (mach_inst) : Machine code of instruction.
     */
    DINTSP_M(ExtMachInst mach_inst);
    
    /**
     * Pure virtual function.
     * EXECUTE fucntions describe how an instruction is executed.
     * 
     * @param (cpu) : Pointer to cpu.
     */
    void execute(RiscCPU *cpu) const;
    
   /**
    * Pure virtual function.
    * 
    * @return : Disassembly language of instruction.
    */
   std::string generate_disassembly(void) const; 
};


} // namespace LILY2_NS

#endif // __RISC_ISA_CATEGORIES_VECTOR_HH__

