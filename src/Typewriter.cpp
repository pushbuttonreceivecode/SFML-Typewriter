#include <Typewriter.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

class Typewriter::impl
{
public:

    explicit impl(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffset);
    ~impl();

public:

    std::string m_string;
    sf::Text m_text;
    float m_offset;
    sf::Vector2f m_position;
    std::size_t m_itr;
    sf::Clock m_timer;
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
};

Typewriter::impl::impl(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffset)
    : m_text(s,f,charSize)
    , m_string(s)
    , m_offset(timeOffset)
    , m_itr(0)
{
    m_text.setColor(sf::Color(255,255,255,255));
    m_text.setOrigin(m_text.getGlobalBounds().width/2.f, 0.f);

    m_buffer.loadFromFile("resources/sounds/type.wav");
    m_sound.setBuffer(m_buffer);
    m_sound.setVolume(50.f);
}

Typewriter::impl::~impl()
{

}

Typewriter::Typewriter(std::string s, sf::Font& f, sf::Uint32 charSize, float timeOffset)
    : m_impl(new impl(s,f,charSize,timeOffset))
{

}

Typewriter::~Typewriter()
{

}

void Typewriter::setString(std::string s)
{
    m_impl->m_string = s;
};

std::string const Typewriter::getString() const
{
    return m_impl->m_string;
};

void Typewriter::setPosition(sf::Vector2f position)
{
    m_impl->m_text.setPosition(position);
};

void Typewriter::reset()
{
    m_impl->m_timer.restart();
    m_impl->m_itr = 0;
};

void Typewriter::write()
{
    //std::cout<<"Writing...."<<std::endl;
    if(m_impl->m_timer.getElapsedTime().asSeconds() > m_impl->m_offset && m_impl->m_itr < m_impl->m_string.size())
    {
        m_impl->m_timer.restart();
        m_impl->m_itr++;

        if(m_impl->m_sound.getStatus() == sf::Sound::Stopped)
            m_impl->m_sound.play();

        m_impl->m_text.setString(sf::String(m_impl->m_string.substr(0, m_impl->m_itr)));

        m_impl->m_text.setOrigin(m_impl->m_text.getGlobalBounds().width/2.f, 0.f);

        //std::cout<<m_impl->m_string.substr(0, m_impl->m_itr)<<std::endl;
    }
}

void Typewriter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_impl->m_text, states);
}
