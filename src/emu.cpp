#include <iostream>
#include "cpu.h"
#include "interface.h"

int main(){
	uint8_t memory[0xFFF];
	char unhalt;
	Cpu cpu;
	cpu.Init();
	while(cpu.EmuState() == 0){
		cpu.Tick(memory[cpu.CountOut()]);
		std::cout << "tick " << cpu.CountOut() << std::endl;
}
}
