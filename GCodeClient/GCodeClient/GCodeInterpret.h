#pragma once

#ifdef GCodeInterpret_EXPORTS
#define GCodeInterpret_API __declspec(dllexport)
#else
#define GCodeInterpret_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

namespace gcode
{
	class GCodeInterpret_API Writer
	{
	public:
		virtual void Write(std::string data) = 0;
	};

	class GCodeInterpret_API  TXTWriter : public Writer
	{
	public:
		void Write(std::string data);
	};

	class GCodeInterpret_API ZPos
	{
	public:
		const static unsigned char Top; // = 180
		const static unsigned char Bottom; // = 40
	};

	class GCodeInterpret_API GCodeInterpret
	{
	private:
		void AddToHistory(std::string& cmd);
		void pop_back(const unsigned char& count);

		std::vector<std::string>* history = nullptr;
		 

		double _relX;
		double _relY;

		double CalculateX(const double& x);
		double CalculateY(const double& y);

		double _currentX;
		double _currentY;

		void AddHeader();
		

		std::string WaitMoveProcess(bool saveToHistory = true);/*
		��������� ��������. ������� M400
		������� ����� ���������� ����������� ������� �� ����.
		����� � public �������, �� �������������� �������� ��� ����������,
		�� ������������� ���������� ����� ������� ������ Move.
		������� � public �� ������ ������, �������� ����� � private ��������, ���� � ��� �� ����� ����������
		*/
		std::string Delay(const unsigned long& millis, bool saveToHistory = true);

		std::string OffPower(bool saveToHistory = true);
	public:
		GCodeInterpret();
		~GCodeInterpret();
		
		std::string SetSpeed(const unsigned long& speed, bool saveToHistory = true);

		std::string MoveToStartPosition(bool saveToHistory = true);

		std::string MoveX(const double& x, bool saveToHistory = true);
		std::string MoveX(const double& x, const unsigned long& speed, bool saveToHistory = true);

		std::string MoveY(const double& y, bool saveToHistory = true);
		std::string MoveY(const double& y, const unsigned long& speed, bool saveToHistory = true);

		std::string MoveXY(const double& x, const double& y, bool saveToHistory = true);
		std::string MoveXY(const double& x, const double& y, const unsigned long& speed, bool saveToHistory = true);

		std::string Capture(bool saveToHistory = true);
		std::string Release(bool saveToHistory = true);


		//std::string MoveZ(const ZPos& pos, bool saveToHistory = true);
		std::string MoveZ(const unsigned short& z, bool saveToHistory = true);/*
		�������� ������������ �������� ��������� Z: 0-180
		���� �������� ������������ ��������, ���������� ���������� ���� std::exception
		*/

		std::string Up(bool saveToHistory = true);
		std::string Down(bool saveToHistory = true);
		
		

		void SetRelativeCoordinates(const double& x, const double& y);/*
		������ ������ ������������� ���������
		������: ���� ������ ������� x=20 y=20, �� ��� ��������� ������� Move � ����������
		���������� x, y ��� ����� ����������� � ��������� ��������������. 
		�� ���� ��� ������� ������� ������ ���������� ����� ������� ����� � ����������� ������ ����������� �����
		������������ ������������ �. �� ��������� (�� ������ ����� ������) �=0 � y=0
		*/
		
		double& GetCurrentX();
		double& GetCurrentY();

		void AddFooter();
		void RemoveFooter();

		std::vector<std::string>& GetHistory();
		void ClearHistory();
		void SaveHistory(Writer* writer);
		void RemoveLast(size_t count = 1);
	};
}