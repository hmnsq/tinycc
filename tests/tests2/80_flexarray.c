#அந்தர்பாவ <stdio.h>
கட்டமைப்பு wchar {
    எழுத்து *data; எழுத்து mem[];
};
கட்டமைப்பு wint {
    எழுத்து *data; முழு mem[];
};
முழு f1char (வெறுமை) {
    எழுத்து s[9]="nonono";
    கட்டமைப்பு wchar q = {"bugs"};
    திரும்பு !s[0];
}
முழு f1int (வெறுமை) {
    எழுத்து s[9]="nonono";
    கட்டமைப்பு wint q = {"bugs"};
    திரும்பு !s[0];
}
முழு empty[] = {}; // GNU extension
முழு முதன்மை (வெறுமை) {
   எழுத்து s[9]="nonono";
   நிலையான கட்டமைப்பு wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   எனில் (f1char() || f1int())
     printf ("bla\n");
   திரும்பு !s[0];
}
