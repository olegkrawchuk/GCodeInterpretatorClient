#include "Header.h"


int main()
{
	setlocale(0, "ru");

	/*
	������ ����� ���������� std::string � �� ��������� ��������� ������ ������������
	������� � �������, ���� �� ������� �������� saveToHistory = false
	������� ������ ����� �������� ������� ClearHistory, ����� �������� � ������� ������ GetHistory � ���� vector<string> 
	� ��������� ������� SaveHistory, ������� ��������� �� ������ ������-���������� Writer.
	�� ������ ������ ����������� ������ ���� � txt ����
	*/

	
	

	GCodeInterpret interpret;
	//interpret.SetRelativeCoordinates(28, 33);

	interpret.MoveXY(10.5, 10.5);
	interpret.Down();
	interpret.Capture();
	interpret.Up();
	interpret.MoveXY(20.5, 31);
	interpret.RemoveLast(2);

	/*
	TXTWriter ������� txt ����, � �������� �������� - ���� � ����� ����������
	��������� ����� � ����������� ������
	*/
	Writer* writer = new TXTWriter();

	interpret.SaveHistory(writer);

	delete writer;

	system("pause");
	system("cls");//������� �������

	//��������� �������
	auto history = interpret.GetHistory();
	for(auto const& i : history)
		std::cout << i << std::endl;

	interpret.ClearHistory();
	std::cout << "\n\n������� �������" << std::endl;

	/*auto history2 = interpret.GetHistory();
	std::cout << "���-�� ��������� �������: " << history2.size() << std::endl;*/

	system("pause");
	return 0;
}