#అన్తర్భావ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
నిర్మాణం vec {
        దశాంశం x;
        దశాంశం y;
};

శూన్య bug(దశాంశం x, దశాంశం y) {
    రాయి("x=%f\ny=%f\n", x, y);
}

దశాంశం dot(నిర్మాణం vec v) {
    తిరిగి 999.5;
}

శూన్య ప్రధాన(శూన్య) {
        నిర్మాణం vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}

