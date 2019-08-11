#include "Header.h"


int main()
{
	setlocale(0, "ru");

	/*
	Каждый метод возвращает std::string и по умолчанию сохраняет каждую возвращенную
	команду в историю, если не указать параметр saveToHistory = false
	Историю команд можно очистить методом ClearHistory, можно получить с помощью метода GetHistory в виде vector<string> 
	и сохранить методом SaveHistory, передав указатель на объект класса-наследника Writer.
	На данный момент реализована запись лишь в txt файл
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
	TXTWriter создает txt файл, у которого название - дата и время сохранения
	Создается рядом с исполняемым файлом
	*/
	Writer* writer = new TXTWriter();

	interpret.SaveHistory(writer);

	delete writer;

	system("pause");
	system("cls");//очищаем консоль

	//получение истории
	auto history = interpret.GetHistory();
	for(auto const& i : history)
		std::cout << i << std::endl;

	interpret.ClearHistory();
	std::cout << "\n\nИстория очищена" << std::endl;

	/*auto history2 = interpret.GetHistory();
	std::cout << "Кол-во элементов истории: " << history2.size() << std::endl;*/

	system("pause");
	return 0;
}