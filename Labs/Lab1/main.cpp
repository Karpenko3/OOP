#include <iostream>
#include <string>
#include <iomanip>
#include "header.h"

using namespace std;


int ukrLenMain(string text) {
    int count = 0;
    for (unsigned char c : text) {
        if (c > 127) count++; 
    }
    return count / 2; 
}

void printCell(string text, int width) {
    cout << left << setw(width + ukrLenMain(text)) << text;
}


void print_table(Detail arr1[], Detail arr2[], Detail arr3[]) {
    string line = "---------------------------------------------------------------";
    cout << "\n  Опис деталей" << endl;
    cout << line << endl;
    cout << "| "; printCell("Найменування", 18);
    cout << "| "; printCell("Тип", 8);
    cout << "| "; printCell("Кількість", 12);
    cout << "| "; printCell("Вага 1 дет.(г)", 15);
    cout << " |" << endl;
    cout << "| " << string(59, '-') << " |" << endl;

    arr1[0].show(); 
    arr2[0].show(); 
    arr3[0].show(); 

    cout << line << endl;
    cout << "  Примітка: О - оригінальна, П - покупна, З - запозичена" << endl;
    cout << line << endl;
}


void edit_detail(Detail &d) {
    int choice;
    cout << "\nЩо ви хочете змінити у деталі?\n";
    cout << "1 - Назву\n2 - Тип\n3 - Кількість\n4 - Вагу\n0 - Скасувати\nВибір: ";
    cin >> choice;

    if (choice == 1) {
        string n; cout << "Нова назва: "; cin >> n;
        d.set_name(n);
    } else if (choice == 2) {
        string t; cout << "Новий тип (О, П, З): "; cin >> t;
        d.set_type(t);
    } else if (choice == 3) {
        int c; cout << "Нова кількість: "; cin >> c;
        d.set_count(c);
    } else if (choice == 4) {
        int w; cout << "Нова вага (г): "; cin >> w;
        d.set_weight(w);
    }
    if (choice != 0) cout << "[OK] Дані деталі успішно оновлено!\n";
}


void print_analytics(Detail &d1, Detail &d2, Detail &d3) {
    cout << "\n  Звіт(Загальна маса на складі) :\n";
    
    Detail* items[3] = {&d1, &d2, &d3};
    for(int i = 0; i < 3; i++) {
        long total_weight = items[i]->get_count() * items[i]->get_weight();
        cout << "- " << items[i]->get_name() 
             << " (Тип " << items[i]->get_type() << "): " 
             << items[i]->get_count() << " шт. -> Загальна вага: " 
             << total_weight << " г.\n";
    }
    cout << "--------------------------------------------------\n\n";
}



int main() {
    cout << "--- Початок роботи з даними ---\n" << endl;

    Detail arr1[1]; 
    arr1[0].set_name("Фланець"); 
    arr1[0].set_type("З"); 
    arr1[0].set_count(3); 
    arr1[0].set_weight(450);


    string t_name, t_type; int t_count, t_weight;
    cout << "Введіть дані для другої деталі (Перехідник, П, 8, 74):\n";
    cout << "Назва: "; cin >> t_name;
    cout << "Тип: "; cin >> t_type;
    cout << "Кількість: "; cin >> t_count;
    cout << "Вага: "; cin >> t_weight;
    Detail arr2[1] = { Detail(t_name, t_type, t_count, t_weight) };

    
    Detail arr3[1] = { Detail(arr1[0]) }; 
    arr3[0].set_name("Станина"); 
    arr3[0].set_type("О"); 
    arr3[0].set_count(1); 
    arr3[0].set_weight(117050);


    // Меню вибору
    int main_choice;
    do {
        cout << "\n--- ГОЛОВНЕ МЕНЮ ---\n";
        cout << "1 - Показати таблицю деталей (show)\n";
        cout << "2 - Редагувати деталь (set) \n";
        cout << "3 - Звіт по складу (get)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> main_choice;

        if (main_choice == 1) {
            print_table(arr1, arr2, arr3); 
        } 
        else if (main_choice == 2) {
            int target;
            cout << "\nЯку деталь редагувати? (1 - Фланець, 2 - Перехідник, 3 - Станина): ";
            cin >> target;
            if (target == 1) edit_detail(arr1[0]);
            else if (target == 2) edit_detail(arr2[0]);
            else if (target == 3) edit_detail(arr3[0]);
            else cout << "Помилка! Такої деталі немає.\n";
        }
        else if (main_choice == 3) {
            print_analytics(arr1[0], arr2[0], arr3[0]);
        }
    } while (main_choice != 0);

    return 0;
}