#include <iostream>

class Cpu{

	uint16_t P0,P1,P2,P3;
	uint8_t ACC,EXT,ST;
	/* Status Register Flags/Bits
	*7: Carry/Link
	*6: Overflow
	*5: Sense B
	*4: Sense A
	*3: Interrupt Enable
	*2: User Flag 2
	*1: User Flag 1
	*0: User Flag 0
	*/

	int EmuAccuracy = 1; 
	/*Emulation accuracy level:
	*0: halt on illegal instruction 
	*1: treat illegal instruction like NOP
	*2: reserved for future cycle accuracy stuffs
	*/

	enum State{ RUN = 0, HALT = 1, STEP = 2 };
	State emustate = RUN;

	public:
	void Init(){
		P0 = 0x0000; //Clear P0/PC
		P0 = P0 + 1; //Account for the SC/MP's weird behavior of incrementing the Program Counter before fetching an instruction.
		ST = 0x00; //Clear the Status Register
	}

	int EmuState(){
		if( emustate == RUN ){return 0;}
		else if( emustate == HALT ){return 1;}
		else{return 2;}
	}

	void SetEmuState(int arg){
		emustate = static_cast<State>(arg);
	}

	int PCounterOut(){
		return P0;
	}

	void Tick(int memory){
		P0++; //Yet again, increment PC before `fetching` an instruction.
		switch(memory){
	case 0x00: //HALT, this one should be interesting (Pulse H-flag, as the programming and assembler manual says)
	
	break;
	case 0x01: //XAE - Exchange AC and Extension
	
	break;
	case 0x02: //CCL - Clear Carry/Link
	
	break;
	case 0x03: //SCL - Set Carry/Link
	
	break;
	case 0x04: //DINT - Disable Interrupts
	
	break;
	case 0x05: //IEN - Enable Interrupts
	
	break;
	case 0x06: //CSA - Copy Status to AC
	
	break;
	case 0x07: //CAS - Copy AC to Status
	
	break;
	case 0x08: //NOP. Do nothing*, waste a cycle (increment PC actually)
	P0++;
	break;
	case 0x19: //SIO - Serial Input/Output
	break;
	case 0x1C: //SR - Shift Right
	ACC = ACC >> 1;
	break;
	case 0x1D: //SRL - Shift Right with CY/L
	
	break;
	case 0x1E: //RR - Rotate Right
	
	break;
	case 0x1F: //RRL - Rotate right with CY/L
	
	break;
	case 0x30: //XPAL - Exchange Pointer Low
	
	break;
	case 0x34: //XPAH - Exchange Pointer High
	
	break;
	case 0x3C: //XPPC - Exchange Pointer with PC
	
	break;
	case 0x40: //LDE - Load from Extension
	ACC = EXT;
	break;
	case 0x50: //ANE - AND Extension
	ACC = ACC & EXT;
	break;
	case 0x58: //ORE - OR Extension
	ACC = ACC | EXT;
	break;
	case 0x60: //XRE - Exclusive-OR Extension
	ACC = ACC ^ EXT;
	break;
	case 0x68: //DAE - Decimal Add Extension
	
	break;
	case 0x70: //ADE - Add Extension
	
	break;
	case 0x78: //CAE - Complement and Add Extension
	
	break;
	case 0x8F: //DLY - Delay, like NOP but more specific?
	
	break;
	case 0x90: //JMP - Jump
	
	break;
	case 0x94: //JP - Jump If Positive
	
	break;
	case 0x98: //JZ - Jump If Zero
	
	break;
	case 0x9C: //JNZ - Jump If Not Zero
	
	break;
	case 0xA8: //ILD - Increment and Load
	
	break;
	case 0xB8: //DLD  - Decrement and Load
	
	break;
	case 0xC0: //LD - Load
	
	break;
	case 0xC4: //LDI - Load Immediate
	
	break;
	case 0xC8: //ST - Store
	
	break;
	case 0xD0: //AND - AND, durr
	
	break;
	case 0xD4: //ANI - AND Immediate
	
	break;
	case 0xD8: //OR - OR, also durrrr
	
	break;
	case 0xDC: //ORI - OR Immediate
	
	break;
	case 0xE0: //XOR - Exclusive-OR
	
	break;
	case 0xE4: //XRI - Exclusive-OR Immediate
	
	break;
	case 0xE8: //DAD - Decimal Add
	
	break;
	case 0xEC: //DAI - Decimal Add Immediate
	
	break;
	case 0xF0: //ADD - Add
	
	break;
	case 0xF4: //ADI - Add Immediate
	
	break;
	case 0xF8: //CAD - Complement and Add
	
	break;
	case 0xFC: //CAI - Complement and Add Immediate
	
	break;
	default:
	if(EmuAccuracy == 0){
		std::cout << "Illegal Instruction at 0x" << std::hex << PCounterOut() << ": 0x" << std::hex << memory << std::endl;
		SetEmuState(HALT);
	}
	else if(EmuAccuracy == 1){
		P0++;
	}	
		}
	}
};
