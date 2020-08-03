package us.codecraft.tinyioc.beans;

import us.codecraft.tinyioc.beans.io.ResourceLoader;

import java.util.HashMap;
import java.util.Map;

/**
 * 从配置中读取BeanDefinition
 * 实现了BeanDefinitionReader接口，规范了BeanDefinitionReader的基本结构。
 *
 * @author yihua.huang@dianping.com
 */
public abstract class AbstractBeanDefinitionReader implements BeanDefinitionReader {

    //内置了一个HashMap，用于保存String-BeanDefinition的键值对，String就是Bean的名字
    private Map<String,BeanDefinition> registry;
    //用于保存类加载器
    private ResourceLoader resourceLoader;
    //构造器
    protected AbstractBeanDefinitionReader(ResourceLoader resourceLoader) {
        this.registry = new HashMap<String, BeanDefinition>();
        this.resourceLoader = resourceLoader;
    }

    public Map<String, BeanDefinition> getRegistry() {
        return registry;
    }

    public ResourceLoader getResourceLoader() {
        return resourceLoader;
    }
}
