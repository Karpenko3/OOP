#include "Header.h"
#include <vector>

int main() {
    
    MASTER owner1("Іваненко Іван", 1001);
    owner1.add_dog(DOG("Рекс", 12.5, 3));
    owner1.add_dog(DOG("Мухтар", 25.0, 5));

    MASTER owner2;
    owner2.set_pib("Петренко Петро");
    owner2.add_dog(DOG("Бобік", 8.2, 1));

    vector<MASTER*> club;
    club.push_back(&owner1);
    club.push_back(&owner2);

    int choice;
    do {
        cout << "\nМЕНЮ КЛУБУ\n";
        cout << "1. Показати всіх членів клубу\n";
        cout << "2. Додати собаку власнику\n";
        cout << "3. Додати нового власника\n"; 
        cout << "4. Показати статистику клубу (static лічильник)\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- СПИСОК ЧЛЕНІВ КЛУБУ ---\n";
            for (MASTER* m : club) {
                m->show();
            }
        } 
        else if (choice == 2) {
            int owner_idx;
            cout << "\nВиберіть порядковий номер власника (1 - " << club.size() << "): ";
            cin >> owner_idx;
            
            if (owner_idx >= 1 && owner_idx <= club.size()) {
                string d_name; float d_weight; int d_age;
                cout << "Кличка собаки: "; cin >> d_name;
                cout << "Вага (кг): "; cin >> d_weight;
                cout << "Вік: "; cin >> d_age;
                
                club[owner_idx - 1]->add_dog(DOG(d_name, d_weight, d_age));
                cout << "[OK] Собаку успішно додано!\n";
            } else {
                cout << "Помилка: такого власника не існує.\n";
            }
        }
        else if (choice == 3) {
            string m_pib; int m_id;
            cout << "Введіть ПІБ власника (без пробілів, наприклад Іванов_І.І.): "; 
            cin >> m_pib;
            cout << "Введіть ID клубу: "; 
            cin >> m_id;
            
            MASTER* new_owner = new MASTER(m_pib, m_id);
            club.push_back(new_owner);
            cout << "[OK] Власника успішно додано!\n";
        }
        else if (choice == 4) {
            cout << "\nЗагальна кількість створених анкет власників: " << MASTER::get_count() << "\n";
        }
    } while (choice != 0);

    for (size_t i = 2; i < club.size(); i++) {
        delete club[i];
    }

    return 0;
}