#include "snake.hpp"


#include <cstdint>
#include <string>




class Game 
{
public:
    Game();
    ~Game();
    void run();

private:
    void read_input();
    void update();
    void draw();

    void setup_screen();
    void restore_screen();
    void hide_cursor();
    void show_cursor();
    void reset_cursor();
    void send_ANSI_escape_code(const std::string& code);
    



    static constexpr uint16_t SCREEN_HEIGHT = 40;
    static constexpr uint16_t SCREEN_WIDTH = 40;
    static constexpr char BORDER_GLYPH = '#';


    Snake m_snake;
    

    bool is_running = true;

};



enum class State 
{
    START_SCREEN,
    IN_GAME,
    LOSE_SCREEN
};