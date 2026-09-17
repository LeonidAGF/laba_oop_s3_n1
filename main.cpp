#include "src/str_ops.h"

int main()
{

	char in;
	char* in_str = nullptr;
	char* buff = nullptr;
	char in_c;

	while (1) {

		std::cout << "1.input string\n2.print\n3.length\n4.copy to buffer and print\n5.to_upper\n6.count inputed char\n0.exit\n";

		if (!(std::cin >> in)) { 
			std::cin.clear();
			break;
		}

		if (in == '1') {
			if (in_str != nullptr) {
				delete[] in_str;
				in_str = nullptr;
			}
			in_str = str_input();
		}
		else if (in == '2') {
			str_print(in_str);
		}
		else if (in == '3') {
			std::cout << str_len(in_str) << "\n";
		}
		else if (in == '4') {
			if (buff != nullptr) {
				delete[] buff;
				buff = nullptr;
			}
			str_copy(buff, in_str);
		}
		else if (in == '5') {
			str_to_upper(in_str);
			str_print(in_str);
		}
		else if (in == '6') {

			if (!(std::cin >> in_c)) {
				std::cin.clear();
				break;
			}
			std::cout << str_count_char(in_str, in_c) << "\n";

		}
		else if (in == '0') {
			if(in_str!=nullptr)
				delete[] in_str;
			in_str = nullptr;
			if (buff != nullptr) {
				delete[] buff;
				buff = nullptr;
			}
			std::cin.clear();
			return 0;
		}
		else
			std::cout << "not expected string\n";

	}

	if (buff != nullptr) {
		delete[] buff;
		buff = nullptr;
	}
	if (in_str != nullptr)
		delete[] in_str;
	in_str = nullptr;
	std::cin.clear();
	return 0;
}
