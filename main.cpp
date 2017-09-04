#include "JaroWinkler.h"

void PrintResults(string& s1, string& s2, JaroObj& _IJaroIns)
{
    static int exampleCount(0);

    const clock_t begin_time = clock();
    double jaroDis = _IJaroIns.jaroDistance(s1, s2);
    float timeTakenJ = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    
    const clock_t begin_timeJ = clock();
    double jarWrinkDis = _IJaroIns.jaroWinklerDistance(s1, s2);
    float timeTakenJW = float( clock () - begin_timeJ ) /  CLOCKS_PER_SEC;

    cout
        << fixed << s1 << " | " << s2 << endl
        << "  Jaro distance:         " << jaroDis << endl
        << "Took: " << timeTakenJ*1000 << " milliseconds" << endl
        << "  Jaro Optimized distance: " << jarWrinkDis << endl
        << "Took: " << timeTakenJW*1000 << " milliseconds" << endl
        << scientific << endl
        ;
}

int main() {
	//string name1 = "varunsdfsdfasdfasdfasdfasf";
	//string name2 = "abbaaaazzzzzzzaaaaasdfaaaaasadfasfs";
	//string name1 = "Chris";
	//string name2 = "Crhis";
	//string name1 = "Chris";
	//string name2 = "Bob";
	string name1 = "Ramanjuna";
	string name2 = "Ramjuna";

	JaroObj* JaroIns = new JaroObj();
	PrintResults(name1, name2, *JaroIns);
	return 0;
}