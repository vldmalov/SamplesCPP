int main()
{
	int arg{ 0 };
	while (!std::cin.fail())
	{
		std::cout << "Enter factorial argument (int) or any other key to exit: ";
		if(std::cin >> arg)
		{
			std::cout << arg << "! = " << factorial(arg) << std::endl;
		}
	};

	return 0;
}
