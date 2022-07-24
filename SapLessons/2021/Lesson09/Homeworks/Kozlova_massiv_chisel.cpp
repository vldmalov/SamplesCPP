#include <iostream>
#include <iomanip>

int main()
{

	float mas[] = { 1, 2, 3, -1,
					2, 52, -10, 5.2222,
					4, 0, 555, -6,
					-0.256, 1, 0, 2.3
	};

	int dlina, max = 0;
	for (int i = 0; i < sizeof(mas); i++)
	{
		dlina = sizeof(mas[i]);
		if (dlina > max) {
			max = dlina;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::cout.width(max) << std::right << mas[i * j + j];
		}
		std::cout << std::endl;
	}
return 0;
}

// int main()
// {
//     const int DIM = 5;
//     const float mas[DIM*DIM] = {
//             1.f, 2, 3, -1, 1,
//             2, 52, -10, 5.2222345343657457467, 1,
//             4, 0, 555, -6, 1,
//             -0.256, 1, 0, 2.3, 1,
//             -0.256, 1, 0, 2.3, 1,
//     };

//     std::cout.precision(1);
//     std::cout.setf(std::ios::fixed);

//     for (int i = 0; i < DIM; i++) {
//         for (int j = 0; j < DIM; j++)
//         {
//             const float val = mas[i * DIM +  j];
//             std::cout.width(10);
//             std::cout << std::right << val << " ";
//         }
//         std::cout << std::endl;
//     }
// }