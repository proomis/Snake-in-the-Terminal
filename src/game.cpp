#include "game.hpp"
#include <conio.h>
#include <iostream>
#include <string>

Game::Game()
{

}

Game::~Game()
{

}

void Game::run()
{
    // save terminal screen
    setup_screen();
    hide_cursor();



    std::cout << "running..." << '\n';
    std::cout << "type Q to quit" << '\n';
    while (is_running)
    {
        read_input();
        update();
        draw();
    }

    // restore saved terminal screen
    restore_screen();
    show_cursor();
}


/* 
    private methods 
*/


void Game::read_input()
{
    if (!_kbhit())
        return;
    
    char ch = _getch();
    std::cout << "you typed: "  << ch << '\n';
    if ('Q' == ch || 'q' == ch)
    {
        is_running = false;
    }

}


void Game::update()
{

}

void Game::draw()
{
    reset_cursor();
    
    for (size_t x = 0; x < this->SCREEN_WIDTH; x++)
        std::cout << this->BORDER_GLYPH;
    std::cout << '\n';
    
    for (size_t y = 0; y < this->SCREEN_HEIGHT-2; y++)
    {
        std::cout << this->BORDER_GLYPH;
        for (size_t x = 0; x < this->SCREEN_WIDTH-2; x++)
            std::cout << ' ';
        std::cout << this->BORDER_GLYPH;
        std::cout << '\n';
    }
    
    for (size_t x = 0; x < this->SCREEN_WIDTH; x++)
        std::cout << this->BORDER_GLYPH;
    std::cout << '\n';
    
    
    
    
    // draw snake
    // draw fruit
}


void Game::setup_screen()
{
    send_ANSI_escape_code("\033[?1049h");
}

void Game::restore_screen()
{
    send_ANSI_escape_code("\033[?1049l");
}

void Game::hide_cursor()
{
    send_ANSI_escape_code("\033[?25l");
}

void Game::show_cursor()
{
    send_ANSI_escape_code("\033[?25h");
}

void Game::reset_cursor()
{
    send_ANSI_escape_code("\033[H");
}



void Game::send_ANSI_escape_code(const std::string& code)
{
    std::cout << code << std::flush;
}