/* Learn: RAII ties resource release to object lifetime; smart pointers express heap ownership.
Why: destructors run when scope ends, including when an exception leaves the scope.
Use: prefer automatic objects, then unique_ptr for exclusive heap ownership.
Watch out: shared_ptr is not a default; cycles can leak and shared ownership complicates design.
Try next: Replace the int with a small class and observe when its destructor runs. */
#include <iostream>
#include <memory>
#include <string>

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
