class Free {
public:
    int trash;
    int secret;
};

int hack_it(Keeper object) {
    Keeper* link = &object;
    auto hacked = (Free*)link;
    return hacked->secret;
}