#include <iostream>
#include <memory>

class FileLikeResource
{
public:
    FileLikeResource() { std::cout << "Resource acquired\n"; }
    ~FileLikeResource() { std::cout << "Resource released\n"; }
};

int main()
{
    FileLikeResource automaticResource; // RAII: its destructor runs on every normal scope exit.

    auto number = std::make_unique<int>(42); // Exclusive ownership; no delete is needed.
    std::cout << "Unique value: " << *number << '\n';

    auto firstOwner = std::make_shared<std::string>("shared text");
    auto secondOwner = firstOwner;
    std::cout << "Owners: " << firstOwner.use_count() << ", value: " << *secondOwner << '\n';

    // Prefer automatic objects. Use unique_ptr for heap ownership; use shared_ptr only for real shared ownership.
}
