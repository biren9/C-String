
#include "String.h"

ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}


int main() {

    String s;
    String s2('H');
    String s3("Hello");
    String s4(s3);
    String s5("Haus _m See");
    String s6("  ");
    String s7("test");
    
    cout << "Ausgabe s: " << s << endl;
    cout << "Ausgabe s2: " << s2 << endl;
    cout << "Ausgabe s3: " << s3 << endl;
    cout << "---------------" << endl;
    s = s3;
    s2 += s2;
    
    cout << "Das s wird mit s3 Überschrieben: " << s << endl;
    cout << "Das s2 wird mit s2 erweitert: " << s2 << endl;
    cout << "Das 3. Zeichen von Hallo: " << s3[2] << endl;
    cout << "Das 6. Zeichen von Hallo: " << s3[5] << endl;

    
    cout << "---------------" << endl;
    cout << s5 << endl;
    s5[5] = 'a';
    cout << s5 << endl;
    s6 += s7;
    cout << s6 << endl;
    
    
    return 0;
}
