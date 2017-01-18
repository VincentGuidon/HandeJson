#pragma once
class HandleJson2
{
	public:
		HandleJson2() : caca(0), coucou(0) {};
		virtual ~HandleJson2() {};

	private:

		int	caca;
		int coucou;

	public:
		int	getcaca(void);
		int getcoucou(void);
		void setcaca(int c);
		void setcoucou(int c);
};

