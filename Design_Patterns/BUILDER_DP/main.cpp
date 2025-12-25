#include "toy_box.hpp"
#include "toy_box_builder.hpp"
int main()
{
toy_box_builder Builder_1;
toy_box *box_1 = Builder_1.add_car("AUDI")->add_doll("BARBIE")->add_stickers(true)->add_gift_wrap(true)->build();
box_1->show();
toy_box_builder Builder_2;
toy_box *box_2 = Builder_2.add_car("AUDI")->add_doll("BARBIE")->add_gift_wrap(true)->build();
box_2->show();

return 0;
}
