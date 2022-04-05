#ifndef RTV1_BUFFER_HPP
#define RTV1_BUFFER_HPP

#include <glad.h>
#include <vector>
#include "types.hpp"

namespace RTV1{
    namespace GLO{
        template<typename t, GLenum target>
        class Buffer{
            public:
                GLuint name;
                Buffer() {
                    glGenBuffers(1, &name);
                }

                void push(t entry){
                    this->_storage.push_back(entry);
                }

                void allocate(){
                    this->bind();
                    glBufferData(target, sizeof(t) * _storage.size(), &this->_storage[0], GL_STATIC_DRAW);
                    this->configure();
                }

                void bind(){
                    glBindBuffer(target, this->name);
                }

                size_t length(){
                    return this->_storage.size();
                }

                virtual void configure() = 0;


                ~Buffer(){
                    glDeleteBuffers(1, &(this->name));
                }



                static void unBind(){
                    glBindBuffer(target, 0);
                }


            private:
                std::vector<t> _storage;
        };

        class VBO : public Buffer<Types::Vertex, GL_ARRAY_BUFFER>{
            public:
                VBO();
                void configure() override;
        };

        class EBO : public Buffer<GLuint, GL_ELEMENT_ARRAY_BUFFER>{
            public:
                EBO();
                void configure() override;
        };
    };
}

#endif