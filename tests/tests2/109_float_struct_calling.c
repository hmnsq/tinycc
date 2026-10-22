#समावेश <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

काष्ठा Point {
   भग्न x;
   भग्न y;
};

काष्ठा Rect {
   काष्ठा Point शीर्ष_बायाँ;
   काष्ठा Point आकार;
};

भग्न foo(काष्ठा Point p, काष्ठा Rect r) {
   वापस r.आकार.x;
}

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv) {
   काष्ठा Point p = {1, 2};
   काष्ठा Rect r = {{3, 4}, {5, 6}};
   म_लिखो("%f\n", foo(p, r));
   वापस 0;
}
