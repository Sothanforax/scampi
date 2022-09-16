#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <getopt.h>

std::vector<uint8_t> instbuf(0xFFFF);

void load_file(char *fname){
	std::cout << "filename " << fname << std::endl;
FILE* fp = std::fopen(fname,"r");
if(!fp){
	std::cout << "Failed to open file!" << std::endl;
}
std::fread(&instbuf[0],sizeof instbuf[0], instbuf.size(), fp);
std::fclose(fp);
}

void disassemble(){
for(int i = 1; i < instbuf.size(); i++){
	std::cout << "0x" << std::hex << i << " ";
	std::cout << static_cast<int>(instbuf[i]) << static_cast<int>(instbuf[i+1]) << "\t";
	switch(instbuf[i]){
	case 0x00: //HALT, this one should be interesting (Pulse H-flag, as the programming and assembler manual says)
	std::cout << "HALT\n";
	break;
	case 0x01: //XAE - Exchange AC and Extension
	std::cout << "XAE\n";
	break;
	case 0x02: //CCL - Clear Carry/Link
	std::cout << "CCL\n";
	break;
	case 0x03: //SCL - Set Carry/Link
	std::cout << "SCL\n";
	break;
	case 0x04: //DINT - Disable Interrupts
	std::cout << "DINT\n";
	break;
	case 0x05: //IEN - Enable Interrupts
	std::cout << "IEN\n";
	break;
	case 0x06: //CSA - Copy Status to AC
	std::cout << "CSA\n";
	break;
	case 0x07: //CAS - Copy AC to Status
	std::cout << "CAS\n";
	break;
	case 0x08: //NOP. Do nothing*, waste a cycle (increment PC actually)
	std::cout << "NOP\n";
	break;
	case 0x19: //SIO - Serial Input/Output
	std::cout << "SIO\n";
	break;
	case 0x1C: //SR - Shift Right
	std::cout << "SR\n";
	break;
	case 0x1D: //SRL - Shift Right with CY/L
	std::cout << "SRL\n";
	break;
	case 0x1E: //RR - Rotate Right
	std::cout << "RR\n";
	break;
	case 0x1F: //RRL - Rotate right with CY/L
	std::cout << "RRL\n";
	break;
	case 0x30: //XPAL - Exchange Pointer Low
	std::cout << "XPAL P0\n";
	break;
	case 0x31: //XPAL - Exchange Pointer Low
	std::cout << "XPAL P1\n";
	break;
	case 0x32: //XPAL - Exchange Pointer Low
	std::cout << "XPAL P2\n";
	break;
	case 0x33: //XPAL - Exchange Pointer Low
	std::cout << "XPAL P3\n";
	break;
	case 0x34: //XPAH - Exchange Pointer High
	std::cout <<"XPAH P0\n";
	break;
	case 0x35: //XPAH - Exchange Pointer High
	std::cout <<"XPAH P1\n";
	break;
	case 0x36: //XPAH - Exchange Pointer High
	std::cout <<"XPAH P2\n";
	break;
	case 0x37: //XPAH - Exchange Pointer High
	std::cout <<"XPAH P3\n";
	break;
	case 0x3C: //XPPC - Exchange Pointer with PC
	std::cout << "XPPC P0\n";
	break;
	case 0x3D: //XPPC - Exchange Pointer with PC
	std::cout << "XPPC P1\n";
	break;
	case 0x3E: //XPPC - Exchange Pointer with PC
	std::cout << "XPPC P2\n";
	break;
	case 0x3F: //XPPC - Exchange Pointer with PC
	std::cout << "XPPC P3\n";
	break;
	case 0x40: //LDE - Load from Extension
	std::cout << "LDE\n";
	break;
	case 0x50: //ANE - AND Extension
	std::cout << "ANE\n";
	break;
	case 0x58: //ORE - OR Extension
	std::cout << "ORE\n";
	break;
	case 0x60: //XRE - Exclusive-OR Extension
	std::cout << "XRE\n";
	break;
	case 0x68: //DAE - Decimal Add Extension
	std::cout << "DAE\n";
	break;
	case 0x70: //ADE - Add Extension
	std::cout << "ADE\n";
	break;
	case 0x78: //CAE - Complement and Add Extension
	std::cout << "CAE\n";
	break;
	case 0x8F: //DLY - Delay processor for specific amount of time in microcycles (13-131593, refer to technical description.)
	std::cout << "DLY ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x90: //JMP - Jump
	std::cout << "JMP ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x91: //JMP - Jump
	std::cout << "JMP ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x92: //JMP - Jump
	std::cout << "JMP ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x93: //JMP - Jump
	std::cout << "JMP ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x94: //JP - Jump If Positive
	std::cout << "JP ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x98: //JZ - Jump If Zero
	std::cout << "JZ ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0x9C: //JNZ - Jump If Not Zero
	std::cout << "JNZ ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xA8: //ILD - Increment and Load
	std::cout << "ILD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xA9: //ILD - Increment and Load
	std::cout << "ILD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xAA: //ILD - Increment and Load
	std::cout << "ILD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xAB: //ILD - Increment and Load
	std::cout << "ILD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xB8: //DLD  - Decrement and Load
	std::cout << "DLD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xB9: //DLD  - Decrement and Load
	std::cout << "DLD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xBA: //DLD  - Decrement and Load
	std::cout << "DLD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xBB: //DLD  - Decrement and Load
	std::cout << "DLD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC0: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC1: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC2: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC3: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC4: //LDI - Load Immediate
	std::cout << "LDI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC5: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC6: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC7: //LD - Load
	std::cout << "LD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC8: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xC9: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xCA: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xCB: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xCC: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xCD: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xCE: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
		case 0xCF: //ST - Store
	std::cout << "ST ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xD0: //AND - AND, durr
	std::cout << "AND ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xD4: //ANI - AND Immediate
	std::cout << "ANI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xD8: //OR - OR, also durrrr
	std::cout << "OR ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xDC: //ORI - OR Immediate
	std::cout << "ORI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xE0: //XOR - Exclusive-OR
	std::cout << "XOR ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xE4: //XRI - Exclusive-OR Immediate
	std::cout << "XRI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xE8: //DAD - Decimal Add
	std::cout << "DAD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xEC: //DAI - Decimal Add Immediate
	std::cout << "DAI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xF0: //ADD - Add
	std::cout << "ADD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xF4: //ADI - Add Immediate
	std::cout << "ADI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xF8: //CAD - Complement and Add
	std::cout << "CAD ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	case 0xFC: //CAI - Complement and Add Immediate
	std::cout << "CAI ";
	std::cout << std::hex << static_cast<int>(instbuf[i+1]) << std::endl;
	i++;
	break;
	default:
	//std::cout << "INVALID OPCODE" << std::endl;
	std::cout << "DAT/INV: " << std::hex << static_cast<int>(instbuf[i]) << std::endl;
	break;
	}
}
}

int main(int argc, char *argv[]){
	int arguments, option_index;
	option_index = 0;

	static struct option disassemble_options[] = {
		{"file", required_argument, 0, 'f'},
		{"address", required_argument, 0, 'a'},
		{"help", no_argument, 0, 'h'},
		{"usage", no_argument, 0, 'u'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0}
	};

	arguments = getopt_long(argc, argv, "f:a:huv", disassemble_options, &option_index);

	switch(arguments){
		case -1:
			std::cout <<"Usage: --file <SC/MP BINARY> OUTPUT_NAME\n";
			break;
		case 'f':
			load_file(optarg);
			disassemble();
			break;
		case 'a':
			break;
		case 'h':
			break;
		case 'u':
			std::cout <<"Usage: --file <SC/MP BINARY> OUTPUT_NAME\n";
			break;
		case 'v':
			std::cout << "Scampi Disassembler Standalone v0.1\n";
			break;
	}
}
