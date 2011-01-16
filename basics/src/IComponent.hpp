#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <string>

class IComponent {
public:
	IComponent();
	void Initialize();
	void Update();

private:
	std::string mName;
	bool mEnabled;
};

#endif // ICOMPONENT_HPP
