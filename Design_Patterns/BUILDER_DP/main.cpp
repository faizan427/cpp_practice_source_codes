#include "toy_box.hpp"
#include "toy_box_builder.hpp"
int main()
{
toy_box_builder Builder;
toy_box *box_1 = Builder.add_car("AUDI")->add_doll("BARBIE")->add_stickers(true)->add_gift_wrap(true)->build();
return 0;
}
