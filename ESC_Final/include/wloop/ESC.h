#include <Cosa/PWMPin.hh>
#include <Cosa/GPIO.hh>
#include <Cosa/OutputPin.hh>
namespace wlp {

    class ESC {
    public:
        explicit ESC(Board::DigitalPin escPin);

        void test();
		
		void begin();

    private:
		OutputPin esc;
    };

}