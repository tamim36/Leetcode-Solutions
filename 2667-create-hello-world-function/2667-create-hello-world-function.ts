type helloWorldFunc = () => () => string;

const createHelloWorld : helloWorldFunc = () => {
    return () => {
        return 'Hello World'
    };
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */