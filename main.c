#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_QUESTIONS 5
typedef struct {
    char question[50];
    char options[4][64];
    int correctoption;
}Question;

void displayquestion(Question q) {
    printf("%ss\n",q.question);
    for (int i =0; i<4;i++) {
        printf("%d. %s\n",i+1,q.options[i]);
    }
}

int checkanswer(Question q, int user_answer) {
    return(user_answer == q.correctoption);
}

int main() {
    srand(time(NULL));
    Question original_questions[MAX_QUESTIONS] = {
        { "En buyuk yumurtaya sahip kus hangisidir?",
          { "Baykus", "Devekusu", "Yalicapkini", "Agackakan" },
          2 },
        { "Orumceklerin kac bacagi olur?",
          { "7", "8", "6", "5" },
          2 },
        { "Amerika baskani nerede ? ",
          { "The White House", "The Parliament",
            "House of Commons", "Washington DC" },
          1 },
        { "Hollywoodla unlu olan eyalet hangisidir?",
          { "Sydney", "California", "New York", "Paris" },
          2 },
        { "Aslan grubuna ne ad verilir?",
          { "Drift", "Pride", "Flock", "Drove" },
          2 }
    };


    Question questions[MAX_QUESTIONS];
    memcpy(questions,original_questions,sizeof(original_questions));

    int num_questions = MAX_QUESTIONS;
    int score =0;
    printf("Selam! Iste Quiz oyunu..\n");
    for (int i =0; i<MAX_QUESTIONS; i++) {
        int randomindex =rand()%num_questions;
        Question current_question = original_questions[randomindex];
        displayquestion(current_question);
        int user_answer =0;
        printf("Cevabinizi giriniz:");
        scanf("%d",&user_answer);
        if (user_answer >= 1 && user_answer <= 4) {
            if (checkanswer(current_question,user_answer)) {
                printf("Dogru!!\n");
                score++;
            }
            else {
                printf("Yanlis cevap dogru cevap >> %d. %s\n",current_question.correctoption,current_question.options[current_question.correctoption-1]);
            }
        }
        else {
            printf("Gecersiz  giris lutfen tekrar deneyiniz..\n");
        }
        questions[randomindex]=questions[num_questions-1];
        num_questions--;
    }
    printf("Quiz tamamlamdi senin skorun : %d %d\n",score,MAX_QUESTIONS);
    return 0;
}
