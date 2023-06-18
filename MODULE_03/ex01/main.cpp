#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap st("Mr. roboot");

    st.attack("other");
    st.takeDamage(5);
    st.attack("other");
    st.beRepaired(1);
    st.attack("other");
    st.guardGate();
}
