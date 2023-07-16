#include <iostream>
#include <memory>







int main()
{

    // int *normal_ptr = new int(7); 

    // std::cout << *normal_ptr << "\n";

    // delete normal_ptr;
    // normal_ptr = nullptr;
    // std::cout << *normal_ptr << "\n";


    ////Why auto pointer is wrong
    // std::auto_ptr<int> ptr(new int(12));

    // std::cout << *ptr << "\n";

    // int value = *ptr;

    // {
    //     std::auto_ptr<int> ptr_2 = ptr; 
    //     *ptr_2 +=2;
    //     std::cout << *ptr_2  <<"\n";
    // }
    // std::cout << *ptr  <<"\n";


    //shared _pointer
    std::shared_ptr<int> ptr = std::make_shared<int>(13);

    std::cout << *ptr << "\n";

    {
        std::shared_ptr<int> ptr_2 = ptr; 
        *ptr_2 +=2;
        std::cout << *ptr_2  <<"\n";
    }
    std::cout << *ptr  <<"\n";


    //unique _pointer
    std::unique_ptr<int> ptr_u = std::make_unique<int>(11);

    std::cout << *ptr_u << "\n";


    {
        std::unique_ptr<int> ptr_2_u = std::move(ptr_u); 
        *ptr_2_u +=2;
        std::cout << *ptr_2_u  <<"\n";
        ptr_u = std::move(ptr_2_u);
        std::weak_ptr weak = ptr_u;
    }
    std::cout << *ptr_u  <<"\n";

    
    return 0;
}
