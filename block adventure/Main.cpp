# include <Siv3D.hpp> // OpenSiv3D v0.6.10



auto Vec2F(Vec2 &doubled_pos) {
	return Vec2{ doubled_pos.x * Scene::Width(), doubled_pos.y * Scene::Height() };
};

auto Vec2F(double x, double y) {
	return Vec2{ x * Scene::Width(), y * Scene::Height()};
}

class Character {
	static constexpr auto gravity = 9.8;

	Rect r;
	Stopwatch stopwatch;
	Vec2 pos;
	Vec2 velocity{ 0, 0 };
	bool can_jump = false;
	bool is_jump = false;

	Optional<double> y_ground;
	static constexpr double v_0 = 0;

	[[nodiscard]]
	bool Collide(const Array<Line>& walls) {
		
	}

	[[nodiscard]]
	bool CollideTop(const Array<Line> walls) {

	}

	[[nodiscard]]
	bool CollideBottom(const Array<Line>& walls) {

		for (const auto& wall : walls) {
//			if (r.bottom() > )
		}
		
	}

public:
	Character() = delete;
	Character(Vec2 _pos) : r( 20, 20 ), pos(_pos) {}
	Character(double x, double y) : r(20, 20), pos(x, y) {}

	void UpdatePos(const Vec2 p) {
		pos += p;
	}

	void UpdatePos(const double x, const double y) {
		pos += Vec2{ x, y };
	}

	void Jump(const bool _is_jump = false) {
		if (not can_jump) return ;
		is_jump = _is_jump;
		stopwatch.start();
		y_ground = pos.y;
	}

	void Update(const Array<Line>& walls) {
		double x = pos.x;
		double y = pos.y;

		if (is_jump && y_ground.has_value()) {
			const double t = stopwatch.sF();
			y = y_ground.value() + v_0 * t + 0.5 * gravity * t * t;
		}
	}
};

void Main() {
	Window::SetFullscreen(true);
	Scene::SetBackground(Palette::Azure);
	Stopwatch sw;
	constexpr auto g = Vec2{ 0, 9.8*5 };
	constexpr auto v0 = Vec2{ 0, -100 };

	Vec2 pos{ 0, 0 };
	Vec2 velocity{ 0,0 };
	bool is_jump = false;
	bool can_jump = false;

	Line l(Vec2F(0, 0.9), Vec2F(1, 0.9));

	std::function<bool(Vec2&, Line&)> Collide = [](Vec2 &Pos, Line& l) {
		const auto y = l.begin.y;

		return ((y - 200) < Pos.y) ? true : false;
	};

	sw.start();

	while (System::Update()){
		velocity.x = (KeyD.pressed() ? 100 : 0) + (KeyA.pressed() ? -100 : 0);

		pos += velocity * Scene::GetMaxDeltaTime();
		velocity += g * Scene::GetMaxDeltaTime();

		std::clamp<double>(velocity.y, -200, 200);

		if (Collide(pos, l)) {
			velocity.y = (velocity.y > 0 ? 0: velocity.y);
			pos.y = l.begin.y - 200;
		}

		if (KeySpace.down()) {
			velocity.y = v0.y;
		}

		l.draw(5, Palette::White);
		Rect{ static_cast<int>(pos.x), static_cast<int>(pos.y), 200, 200 }.draw(Palette::Black);

	}
}
