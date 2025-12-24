#include <iostream>
using namespace std;

class Player
{
public:
    string name;
    string position;

    Player *prev;
    Player *next;

    Player(string player_name, string player_pos)
    {
        name = player_name;
        position = player_pos;
        prev = nullptr;
        next = nullptr;
    }
};

void display_formation()
{
    cout << "\n========== BARCELONA 4-2-3-1 FORMATION ==========" << endl;
    cout << endl;
    cout << "                  Lewandowski (ST)                " << endl;
    cout << endl;
    cout << "   Raphinha (LW)  Fermin (CAM)  Lamine (RW)      " << endl;
    cout << endl;
    cout << "            Pedri (CM)  Frenkie (CDM)            " << endl;
    cout << endl;
    cout << "  Balde (LB)  Martin (CB)  Cubarsi (CB)  Kounde (RB)" << endl;
    cout << endl;
    cout << "                   Joan (GK)                     " << endl;
    cout << "==================================================\n"
         << endl;
}

void make_substitution(Player **head, string to_replace, string replacement)
{
    Player *current = *head;

    while (current != nullptr)
    {
        if (current->name == to_replace)
        {
            Player *temp = current;
            Player *sub = new Player(replacement, current->position);

            // Set new player's pointers
            sub->next = current->next;
            sub->prev = current->prev;

            // Rewire surrounding nodes
            if (current->prev != nullptr)
            {
                current->prev->next = sub; // Middle or tail case
            }
            else
            {
                *head = sub; // Head case - update head pointer
            }

            if (current->next != nullptr)
            {
                current->next->prev = sub; // Head or middle case
            }

            delete temp; // Free old player's memory
            return;
        }

        current = current->next;
    }

    // Optional: Handle player not found
    cout << "Player " << to_replace << " not found!" << endl;
}

int main()
{
    // starting XI
    Player *lewandowski = new Player("Lewandowski", "ST");
    Player *raphinha = new Player("Raphinha", "LW");
    Player *fermin = new Player("Fermin", "CAM");
    Player *lamine = new Player("Lamine", "RW");
    Player *pedri = new Player("Pedri", "CM");
    Player *frenkie = new Player("Frenkie", "CDM");
    Player *balde = new Player("Balde", "LB");
    Player *martin = new Player("Martin", "CB");
    Player *cubarsi = new Player("Cubarsi", "CB");
    Player *kounde = new Player("Kounde", "RB");
    Player *joan = new Player("Joan", "GK");

    // bench
    Player *ferran = new Player("Ferran", "ST");
    Player *bernal = new Player("Bernal", "CDM");
    Player *rashford = new Player("Rashford", "LW");
    Player *garcia = new Player("Garcia", "CB");
    Player *ter_stegen = new Player("Ter Stegen", "GK");

    // injured
    Player *gavi = new Player("Gavi", "CM");
    Player *araujo = new Player("Araujo", "CB");

    // link starting XI
    lewandowski->prev = nullptr;
    lewandowski->next = raphinha;

    raphinha->prev = lewandowski;
    raphinha->next = fermin;

    fermin->prev = raphinha;
    fermin->next = lamine;

    lamine->prev = fermin;
    lamine->next = pedri;

    pedri->prev = lamine;
    pedri->next = frenkie;

    frenkie->prev = pedri;
    frenkie->next = balde;

    balde->prev = frenkie;
    balde->next = martin;

    martin->prev = balde;
    martin->next = cubarsi;

    cubarsi->prev = martin;
    cubarsi->next = kounde;

    kounde->prev = cubarsi;
    kounde->next = joan;

    joan->prev = kounde;
    joan->next = nullptr;

    Player *head = lewandowski;

    display_formation();

    cout << "Starting XI Linked List: " << endl;
    Player *current = head;
    while (current != nullptr)
    {
        cout << current->name << " (" << current->position << ") -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    // Test 1: Replace middle player
    cout << "Test 1: Substituting Cubarsi for Garcia" << endl;
    make_substitution(&head, "Cubarsi", "Garcia");
    current = head;
    while (current != nullptr)
    {
        cout << current->name << " (" << current->position << ") -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    // Test 2: Replace head (captain)
    cout << "Test 2: Substituting Lewandowski for Ferran" << endl;
    make_substitution(&head, "Lewandowski", "Ferran");
    current = head;
    while (current != nullptr)
    {
        cout << current->name << " (" << current->position << ") -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    // Test 3: Replace tail (goalkeeper)
    cout << "Test 3: Substituting Joan for Ter Stegen" << endl;
    make_substitution(&head, "Joan", "Ter Stegen");
    current = head;
    while (current != nullptr)
    {
        cout << current->name << " (" << current->position << ") -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    // Test 4: Player not found
    cout << "Test 4: Trying to substitute Messi (not in squad)" << endl;
    make_substitution(&head, "Messi", "Gavi");
    current = head;
    while (current != nullptr)
    {
        cout << current->name << " (" << current->position << ") -> ";
        current = current->next;
    }
    cout << "END" << endl;
}