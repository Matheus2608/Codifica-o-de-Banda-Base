#include "utils.hpp"

bool are_vectors_equal(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (std::size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

vi inicializadorDeClock(int tamanhoQuadro) {
    vi clock;
    if(!tamanhoQuadro) return clock;

    // Prrenchendo o clock com sequencias de "01"
    for (int i = 0; i < tamanhoQuadro * 2; i++) {
        if (i % 2 == 0)
            clock.pb(0);
        else
            clock.pb(1);
    }

    return clock;
}