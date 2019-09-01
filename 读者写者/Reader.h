#include "Story.h"
#define MAX_COUNT 6
using namespace std;

class Creader{
	public:
		Creader(int i);
		~Creader();
		void Read(ItemStory*,bool&);
		
	private:
		int id;
		static int max_count;
		static int reader_count;
};
