#ifndef COMPARE_H
#define COMPARE_H

typedef enum compare_result {
    eNotExpect = -1,
    eEqual, 
    eExpect,
} compare_result_t;

compare_result_t compare_bigger (int first_num, int second_num)
{
    compare_result_t result = eEqual;
    if (first_num > second_num) {
        result = eExpect;
    } else if (first_num < second_num) {
        result = eNotExpect;
    }

    return result;
}

compare_result_t compare_smaller (int first_num, int second_num)
{
    compare_result_t result = eEqual;
    if (first_num < second_num) {
        result = eExpect;
    } else if (first_num > second_num) {
        result = eNotExpect;
    }

    return result;
}
#endif /* end if */