
namespace cpp_test {
    
    //% shim=cpp_test::imul
    export function imul(a: number, b: number): number {
        return (a * b)|0;
    }
}

game.splash(cpp_test.imul(2, 2));