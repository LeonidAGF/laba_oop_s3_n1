#include "laba_oop_s3_n1.h"
#include "str_ops.h"

char* str_input() {
	std::size_t capacity = 10;
	std::size_t size = 0;

	char* str = new char[capacity];
	if (str == nullptr) {
		return nullptr;
	}

	char c;

	while (std::cin.get(c) && c != '\n') {
		if (size + 1 >= capacity) {
			capacity *= 2;

			char* new_str = new char[capacity];
			if (new_str == nullptr) {
				return nullptr;
			}

			for (std::size_t i = 0; i < size; ++i)
				new_str[i] = str[i];
			if(str!=nullptr)
				delete[] str;
			str = new_str;
		}

		str[size] = c;
		++size;
	}

	str[size] = '\0';

	return str;
}

int main()
{

	char in;
	char* in_str = nullptr;
	char* buff = nullptr;
	char* in_c = nullptr;

	while (1) {

		std::cout << "1. input string 2. print 3. length 4. copy to buffer and print 5. to_upper 6. count inputed char 0. exit\n";

		std::cin >> in;

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
			std::cout << str_len(in_str);
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
			if (in_c != nullptr) {
				delete in_c;
				in_c = nullptr;
			}
			in_c = new char;
			if (in_c == nullptr)
				break;
			std::cin >> *in_c;

			std::cout << str_count_char(in_str, *in_c);

			if(in_c!=nullptr)
				delete in_c;
			in_c = nullptr;
		}
		else if (in == '0') {
			if (in_c != nullptr)
				delete in_c;
			in_c = nullptr;
			if(in_str!=nullptr)
				delete[] in_str;
			in_str = nullptr;
			return 0;
		}
		else
			std::cout << "not expected string\n";

	}

	if (in_str != nullptr)
		delete[] in_str;
	in_str = nullptr;
	return 0;
}
