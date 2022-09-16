#pragma once
class BestFirstSearch
{
private:
	int g, f, h;

public:
	int GetG() { return g; }
	int GetF() { return f; }
	int GetH() { return h; }
	void SetG(int value) { g = value; }
	void ComputeH();
	void ComputeF() { f = g + h; }
	bool operator == (const BestFirstSearch &other);

	BestFirstSearch(BestFirstSearch * p, int dir);

};

