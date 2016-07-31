#ifndef MINIASCAPE_CONWAYS_LIFEGAME_SIMULATOR
#define MINIASCAPE_CONWAYS_LIFEGAME_SIMULATOR
#include "Simulator.hpp"
#include "SquareLattice.hpp"
#include "RandomStateGenerator.hpp"
#include "ConwaysLifeGameTraits.hpp"

namespace miniascape
{

class ConwaysLifeGameSimulator
    : public Simulator<SquareLattice, ConwaysLifeGameTraits>
{
  public:
    using traits_type = ConwaysLifeGameTraits;
    using state_type  = typename traits_type::state_type;
    using base_type   = Simulator<SquareLattice, traits_type>;
    using world_type  = base_type::world_type;

  public:
    ConwaysLifeGameSimulator(const time_type t_end,
            const std::size_t v, const std::size_t h)
        : Simulator(t_end), vertical_(v), horizontal_(h)
    {}
    ~ConwaysLifeGameSimulator() = default;

    void initialize() override;
    void finalize() override;

  private:
    const std::size_t vertical_;
    const std::size_t horizontal_;
};

inline void ConwaysLifeGameSimulator::initialize()
{
    this->world_.create(vertical_, horizontal_);
    RandomStateGenerator<state_type> rsg(100);
    this->world_.randomize(rsg);
}

inline void ConwaysLifeGameSimulator::finalize()
{
    return ;
}



}

#endif /* MINIASCAPE_CONWAYS_LIFEGAME_SIMULATOR */
