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
        << "Example " << ++exampleCount << ": "
        << s1 << " vs " << s2 << endl
        << "  Jaro distance:         " << jaroDis << endl
        << "Took: " << timeTakenJ << " seconds" << endl
        << "  Jaro Optimized distance: " << jarWrinkDis << endl
        << "Took: " << timeTakenJW << " seconds" << endl
        << endl
        ;
}

int main() {
	string name1 = "varunsdfsdfasdfasdfasdfasf";
	string name2 = "abbaaaazzzzzzzaaaaasdfaaaaasadfasfs";

	JaroObj* JaroIns = new JaroObj();
	PrintResults(name1, name2, *JaroIns);
	return 0;
}