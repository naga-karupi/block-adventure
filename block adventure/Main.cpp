# include <Siv3D.hpp> // OpenSiv3D v0.6.10

void Main()
{
	Font font{ 50 };

	while (System::Update())
	{
		font( U"siv3d" ).draw(20, 20);
	}
}
