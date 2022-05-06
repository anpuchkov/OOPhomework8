#include <iostream>
#include <vector>

#include "Student.h"

bool gExit = false;
std::vector<Student> entries{};

void printEntries(std::vector<Student>& entries) {
	std::cout << "�\t�������\t���\t��������\t�������\t��� ��������\t������\n";
	size_t s = entries.size();
	for (int i = 0; i < s; ++i) {
		std::cout << i << ".\t" << entries[i] << '\n';
	}
}

void getCommand() {
	std::string input;
	std::cout << "\n\n������� �������: ";
	std::getline(std::cin >> std::ws, input);
	if (input == "help") {
		std::cout <<
			"help � �������� ���� �����.\n"
			"add � �������� ������ � ���������.\n"
			"remove � ������� ������ �� ���������.\n"
			"show � ������� ���������.\n"
			"exit � ����� �� ���������.\n"
			;
		return;
	}
	if (input == "add") {
		std::cout << "������� ������ � ��������� �������\n������� ��� �������� ������� ���_�������� ������\n>";
		Student tmpStudent{};
		std::cin >> tmpStudent;
		tmpStudent.fixWindowsCodepage();
		entries.push_back(tmpStudent);
		return;
	}
	if (input == "remove") {
		std::cout << "������ ������ ��� ��������: ";
		size_t idx = entries.size() - 1;
		std::cin >> idx;
		if (idx < 0 || idx >= entries.size()) {
			std::cout << "������ �� ����������.\n";
			return;
		}
		entries.erase(entries.begin() + idx);
		return;
	}
	if (input == "show") {
		printEntries(entries);
		return;
	}
	if (input == "exit") {
		gExit = true;
		return;
	}
}

int main() {
	std::setlocale(LC_ALL, ".UTF8");
	entries.reserve(3);
	entries.emplace_back(Student("������", "����", "��������", 21, 3, "����-01-19"));
	entries.emplace_back(Student("������", "ϸ��", "��������", 18, 1, "����-01-21"));
	entries.emplace_back(Student("�����", "���", "", 45, -156, "����-01-19"));
	printEntries(entries);

	while (!gExit) {
		getCommand();
	}

	return 0;
}