#pragma once
namespace dhgame {
	class Director
	{
	public:
		~Director();
		static Director* getInstance();
		
	private:
		Director();
	};
}